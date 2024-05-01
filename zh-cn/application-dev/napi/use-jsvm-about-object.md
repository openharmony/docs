# 使用JSVM-API接口进行object相关开发

## 简介

使用JSVM-API接口进行object相关开发，处理JavaScript对象的基本操作的功能，例如创建对象、获取原型、冻结和密封对象，检查对象的类型等。这些操作是在处理JavaScript对象时非常常见的，提供了一种与JavaScript对象交互的方式。

## 基本概念

在JSVM接口开发中，经常需要定义和操作对象。例如，创建一个API接口，该接口接受一个对象作为输入参数，对该对象执行某些操作，并返回一个结果对象。在这个过程中，需要确保接口的定义清晰、规范，并且与对象的属性和方法相兼容。

> - **接口（API）**：接口定义了组件之间的交互协议，包括输入参数、输出结果以及可能的错误处理。通过接口，组件可以相互调用和交换数据，而无需了解对方的内部实现细节。
> - **对象（Object）**：在JavaScript，对象是一种复合数据类型，允许存储多个不同类型的值作为一个单独的实体。对象是属性和方法的集合。属性是与对象相关联的值，而方法则是对象可以执行的操作。

## 接口说明

| 接口                       | 功能说明                                     |
| -------------------------- | -------------------------------------------- |
| OH_JSVM_GetPrototype         | 获取给定JavaScript对象的原型。             |
| OH_JSVM_CreateObject         | 创建一个默认的JavaScript Object对象。                   |
| OH_JSVM_ObjectFreeze         | 冻结给定的对象，防止向其添加新属性，删除现有属性，防止更改现有属性的可枚举性、可配置性或可写性，并防止更改现有属性的值。                             |
| OH_JSVM_ObjectSeal           |  密封给定的对象。这可以防止向其添加新属性，以及将所有现有属性标记为不可配置。                             |
| OH_JSVM_Typeof                | 返回JavaScript对象的类型。  |
| OH_JSVM_Instanceof            | 判断一个对象是否是某个构造函数的实例。    |
| OH_JSVM_TypeTagObject       | 将type_tag指针的值与JavaScript对象或外部对象相关联。                  |
| OH_JSVM_CheckObjectTypeTag | 检查给定的类型标签是否与对象上的类型标签匹配。 |
| OH_JSVM_CreateSymbol         | 根据给定的描述符创建一个Symbol对象。                     |
|OH_JSVM_SymbolFor | 在全局注册表中搜索具有给定描述的现有Symbol，如果该Symbol已经存在，它将被返回，否则将在注册表中创建一个新Symbol |
| OH_JSVM_CreateExternal       | 创建一个包装了外部指针的JavaScript对象               |
| OH_JSVM_GetValueExternal    | 获取先前传递给OH_JSVM_CreateExternal的外部数据指针                  |

## 使用示例

### OH_JSVM_GetPrototype

获取给定JavaScript对象的原型。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，GetPrototype在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetPrototype},
};
static JSVM_CallbackStruct *method = param;
// GetPrototype方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"getPrototype", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// GetPrototype方法添加到jsvm-api.md
static JSVM_Value GetPrototype(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_data_type = "utf8";
    // 创建一个空对象
    JSVM_Value obj = nullptr;
    OH_JSVM_CreateObject(env, &obj);
    const char *testNameStr = "set and get proto";
    JSVM_Value propValue = nullptr;
    JSVM_Value key = nullptr;
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &key);
    OH_JSVM_CreateStringUtf8(env, testNameStr, strlen(testNameStr), &propValue);
    OH_JSVM_SetProperty(env, obj, key, propValue);
    // 获取属性
    JSVM_Value propResult = nullptr;
    JSVM_Status status = OH_JSVM_GetProperty(env, obj, key, &propResult);
    if (status != JSVM_OK) {
        return nullptr;
    }
    return propResult;
}
```

ArkTS侧示例代码

```ts
let script: string = `getPrototype()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getPrototype: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getPrototype error: %{public}s', error.message);
}
```

### OH_JSVM_CreateObject

创建一个默认的JavaScript Object对象。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，CreateObject在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateObject},
};
static JSVM_CallbackStruct *method = param;
// CreateObject方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"createObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// CreateObject方法添加到jsvm-api.md
static JSVM_Value CreateObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_data_type = "object";
    JSVM_Value object = nullptr;
    // 创建一个空对象
    OH_JSVM_CreateObject(env, &object);
    // 设置对象的属性
    JSVM_Value name = nullptr;
    // 设置属性名为 "name"
    OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &name);
    JSVM_Value value = nullptr;
    // 设置属性值为 "Hello from N-API!"
    OH_JSVM_CreateStringUtf8(env, "Hello OH_JSVM_CreateObject!", JSVM_AUTO_LENGTH, &value);
    // 将属性设置到对象上
    OH_JSVM_SetProperty(env, object, name, value);

    return object;
}
```

ArkTS侧示例代码

```ts
let script: string = `createObject()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createObject: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createObject error: %{public}s', error.message);
}
```

### OH_JSVM_ObjectFreeze

冻结给定的对象，防止向其添加新属性，删除现有属性，防止更改现有属性的可枚举性、可配置性或可写性，并防止更改现有属性的值。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，ObjectFreeze在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ObjectFreeze},
};
static JSVM_CallbackStruct *method = param;
// ObjectFreeze方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"objectFreeze", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// ObjectFreeze方法添加到jsvm-api.md
static JSVM_Value ObjectFreeze(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_data_type = "objectstr";
    // 接受一个JavaScript侧传入的object
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 调用接口OH_JSVM_ObjectFreeze将传入的object冻结
    JSVM_Status status = OH_JSVM_ObjectFreeze(env, argv[0]);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectFreeze success");
    }
    // 测试冻结后的对象中属性能否修改
    JSVM_Value value = nullptr;
    OH_JSVM_CreateInt32(env, 111111, &value);
    OH_JSVM_SetNamedProperty(env, argv[0], "data", value);
    // 将冻结后修改过的属性返回JavaScript侧
    return argv[0];
}
```

ArkTS侧示例代码

```ts
let script: string = `
  let obj = { data: 55, message: "hello world"};
  objectFreeze(obj)
`
try {
  let result = napitest.runJsVm(script);
  // 冻结后的对象还是之前的属性值并未修改
  hilog.info(0x0000, 'testJSVM', 'Test JSVM objectFreeze: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM objectFreeze error: %{public}s', error.message);
}
```

### OH_JSVM_ObjectSeal

密封给定的对象。这可以防止向其添加新属性，以及将所有现有属性标记为不可配置。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，ObjectSeal在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ObjectSeal},
};
static JSVM_CallbackStruct *method = param;
// ObjectSeal方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"objectSeal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// ObjectSeal方法添加到jsvm-api.md
static JSVM_Value ObjectSeal(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_data_type = "objectstr";
    // 接受一个JavaScript侧传入的object
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 调用接口OH_JSVM_ObjectSeal将传入的object封闭，使其无法添加新的属性
    JSVM_Status status = OH_JSVM_ObjectSeal(env, argv[0]);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectSeal success");
    }
    // 检查封闭后的对象中属性能否修改、删除、新增
    // 封闭后对象修改
    JSVM_Value changeValue = nullptr;
    OH_JSVM_CreateInt32(env, 111111, &changeValue);
    OH_JSVM_SetNamedProperty(env, argv[0], "data", changeValue);
    // 封闭后对象删除
    JSVM_Value deleteProperty = nullptr;
    OH_JSVM_CreateStringUtf8(env, "message", JSVM_AUTO_LENGTH, &deleteProperty);
    bool result = false;
    OH_JSVM_DeleteProperty(env, argv[0], deleteProperty, &result);
    if (result) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_ObjectSeal failed");
    }
    // 封闭后对象新增
    JSVM_Value addValue = nullptr;
    OH_JSVM_CreateStringUtf8(env, "addValue", JSVM_AUTO_LENGTH, &addValue);
    OH_JSVM_SetNamedProperty(env, argv[0], "newProperty", addValue);
    // 将封闭后改动过的对象返回JavaScript侧
    return argv[0];
}
```

ArkTS侧示例代码

```ts
let script: string = `
  let obj = { data: 55, message: "hello world"};
  objectSeal(obj)
`
try {
  let result = napitest.runJsVm(script);
  // 封闭后的对象输出后显示可以修改但不能删除和新增
  hilog.info(0x0000, 'testJSVM', 'Test JSVM objectSeal: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM objectSeal error: %{public}s', error.message);
}
```

### OH_JSVM_Typeof

返回JavaScript对象的类型。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，GetTypeof在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetTypeof},
};
static JSVM_CallbackStruct *method = param;
// GetTypeof方法别名，TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"getTypeof", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// GetTypeof方法添加到jsvm-api.md
static JSVM_Value GetTypeof(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_ValueType valueType;
    OH_JSVM_Typeof(env, args[0], &valueType);
    JSVM_Value type = nullptr;
    switch (valueType) {
    case JSVM_UNDEFINED:
        OH_JSVM_CreateStringUtf8(env, "Input type is undefined", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_NULL:
        OH_JSVM_CreateStringUtf8(env, "Input type is null", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_BOOLEAN:
        OH_JSVM_CreateStringUtf8(env, "Input type is boolean", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_NUMBER:
        OH_JSVM_CreateStringUtf8(env, "Input type is number", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_STRING:
        OH_JSVM_CreateStringUtf8(env, "Input type is string", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_SYMBOL:
        OH_JSVM_CreateStringUtf8(env, "Input type is symbol", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_OBJECT:
        OH_JSVM_CreateStringUtf8(env, "Input type is object", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_FUNCTION:
        OH_JSVM_CreateStringUtf8(env, "Input type is function", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_EXTERNAL:
        OH_JSVM_CreateStringUtf8(env, "Input type is external", JSVM_AUTO_LENGTH, &type);
        break;
    case JSVM_BIGINT:
        OH_JSVM_CreateStringUtf8(env, "Input type is bigint", JSVM_AUTO_LENGTH, &type);
        break;
    default:
        OH_JSVM_CreateStringUtf8(env, " ", JSVM_AUTO_LENGTH, &type);
        break;
    }
    return type;
}
```

ArkTS侧示例代码

```ts
let script: string = `
getTypeof(true);
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "GetTypeof: %{public}s", result);
} catch (error) {
  hilog.error(0x0000, "JSVM", "GetTypeof: %{public}s", error.message);
}
```

### OH_JSVM_Instanceof

判断一个对象是否是某个构造函数的实例。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，InstanceOf在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = InstanceOf},
};
static JSVM_CallbackStruct *method = param;
// InstanceOf方法别名，TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"instanceOf", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// InstanceOf方法添加到jsvm-api.md
static JSVM_Value InstanceOf(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    OH_JSVM_Instanceof(env, args[0], args[1], &result);
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let script: string = `
      class Person {
        name;
        age;
        constructor(name, age) {
          this.name = name;
          this.age = age;
        }
      }
     instanceOf(new Person('Alice', 30), Person);
     ;
        `;
try {
  let result = napitest.runJsVm(script.toString());
  hilog.info(0x0000, "JSVM", "InstanceOf: %{public}s", result);
} catch (error) {
  hilog.error(0x0000, "JSVM", "InstanceOf: %{public}s", error.message);
} 
```

### OH_JSVM_TypeTagObject

使用类型标签type_tag来标记JavaScript对象，后续可以更精确地识别JavaScript对象。

### OH_JSVM_CheckObjectTypeTag

检查给定的类型标签是否与对象上的类型标签匹配。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，SetTypeTagToObject，CheckObjectTypeTag在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetTypeTagToObject},
    {.data = nullptr, .callback = CheckObjectTypeTag},
};
static JSVM_CallbackStruct *method = param;
// SetTypeTagToObject，CheckObjectTypeTag方法别名，TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"setTypeTagToObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"checkObjectTypeTag", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
#define NUMBERINT_FOUR 4
// 定义一个静态常量JSVM_TypeTag数组存储类型标签
static const JSVM_TypeTag TagsData[NUMBERINT_FOUR] = {
    {0x9e4b2449547061b3, 0x33999f8a6516c499},
    {0x1d55a794c53a726d, 0x43633f509f9c944e},
    {0, 0}, // 用于表示无标签或默认标签
    {0x6a971439f5b2e5d7, 0x531dc28a7e5317c0},
};
// SetTypeTagToObject，CheckObjectTypeTag方法添加到jsvm-api.md
static JSVM_Value SetTypeTagToObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取函数调用信息和参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取索引数字转换为JSVM_Value
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    // 给参数（对象）设置类型标签
    JSVM_Status status = OH_JSVM_TypeTagObject(env, args[0], &TagsData[index]);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, "Reconnect error", "OH_JSVM_TypeTagObject failed");
        return nullptr;
    }
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}

static JSVM_Value CheckObjectTypeTag(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获取函数调用信息和参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取索引数字转换为JSVM_Value
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    // 检查对象的类型标签
    bool checkResult = false;
    OH_JSVM_CheckObjectTypeTag(env, args[0], &TagsData[index], &checkResult);
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value checked = nullptr;
    OH_JSVM_GetBoolean(env, checkResult, &checked);
    return checked;
}
```

ArkTS侧示例代码

```ts
let script: string = `
         class Obj {
           data;
           message;
         }
         let obj= { data: 0, message: "hello world"};
         setTypeTagToObject(obj, 0)
       `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "SetTypeTagToObject: %{public}s", JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, "JSVM", "SetTypeTagToObject: %{public}s", error.message);
}
let script: string = `
         class Obj {
           data;
           message;
         }
         let obj= { data: 0, message: "hello world"};
         setTypeTagToObject(obj,0)
         checkObjectTypeTag(obj,0);
       `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "CheckObjectTypeTag: %{public}s", JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, "JSVM", "CheckObjectTypeTag: %{public}s", error.message);
}
```

### OH_JSVM_CreateExternal

创建一个包装了外部指针的JavaScript对象

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，CreateExternal在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateExternal},
};
static JSVM_CallbackStruct *method = param;
// CreateExternal方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"createExternal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// CreateExternal方法添加到jsvm-api.md
static JSVM_Value CreateExternal(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t dataSize = 10;
    void *data = malloc(dataSize);
    memset(data, 0, dataSize);
    const char testStr[] = "test";
    JSVM_Value external = nullptr;
    JSVM_Status status = OH_JSVM_CreateExternal(
        env, (void *)testStr, [](JSVM_Env env, void *data, void *hint) {}, (void *)testStr, &external);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM Failed to create external data, status:%{public}d.", status);
        return nullptr;
    } else {
        type = true;
    }
    OH_JSVM_GetBoolean(env, type, &returnValue);
    // 返回结果
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let script: string = `createSymbol()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createSymbol: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createSymbol error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueExternal

OH_JSVM_CreateExternal可以创建包装自定义的C/C++对象并将其公开给JavaScript代码，而OH_JSVM_GetValueExternal就是用来获得OH_JSVM_CreateExternal所创建的外部对象的。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，GetValueExternal在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueExternal},
};
static JSVM_CallbackStruct *method = param;
// GetValueExternal方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueExternal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// getValueExternal方法添加到jsvm-api.md
static JSVM_Value GetValueExternal(JSVM_Env env, JSVM_CallbackInfo info)
{
    g_data_type = "int";
    void *data = (void *)0x12345;
    JSVM_Value externalValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateExternal(env, data, nullptr, nullptr, &externalValue);
    if (status != JSVM_OK) {
        // 错误处理
        return nullptr;
    }
    void *data_value;
    status = OH_JSVM_GetValueExternal(env, externalValue, &data_value);
    bool type = false;
    if (status != JSVM_OK) {
        // 错误处理
        return nullptr;
    }
    type = true;
    OH_LOG_INFO(LOG_APP, "JSVM API Get ValueExternal:%{public}p", data_value);
    // 将符号位转化为int类型传出去
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateInt32(env, 0, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let script: string = `getValueExternal()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getValueExternal: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getValueExternal error: %{public}s', error.message);
}
```

### OH_JSVM_CreateSymbol

用于创建一个新的Symbol。Symbol是一种特殊的数据类型，用于表示唯一的标识符。与字符串或数字不同，符号的值是唯一的，即使两个符号具有相同的描述，它们也是不相等的。符号通常用作对象属性的键，以确保属性的唯一性。

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，CreateSymbol在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateSymbol},
};
static JSVM_CallbackStruct *method = param;
// CreateSymbol方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"createSymbol", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// CreateSymbol方法添加到jsvm-api.md
static JSVM_Value CreateSymbol(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value result = nullptr;
    const char *des = "only";
    OH_JSVM_CreateStringUtf8(env, des, JSVM_AUTO_LENGTH, &result);
    JSVM_Value returnSymbol = nullptr;
    OH_JSVM_CreateSymbol(env, result, &returnSymbol);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    JSVM_ValueType valuetypeSymbol;
    OH_JSVM_Typeof(env, returnSymbol, &valuetypeSymbol);
    if (valuetypeSymbol == JSVM_SYMBOL) {
        OH_LOG_INFO(LOG_APP, "JSVM CreateSymbol Success");
        type = true;
    }
    OH_JSVM_GetBoolean(env, type, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let script: string = `createSymbol()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createSymbol: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createSymbol error: %{public}s', error.message);
}
```

### OH_JSVM_SymbolFor

在全局注册表中搜索具有给定描述的现有Symbol，如果该Symbol已经存在，它将被返回，否则将在注册表中创建一个新Symbol

cpp部分代码

```cpp
// jsvm-api.md为基础运行框架，SymbolFor在jsvm-api.md注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SymbolFor},
};
static JSVM_CallbackStruct *method = param;
// SymbolFor方法别名，供TS侧调用。在jsvm-api.md进行添加
static JSVM_PropertyDescriptor descriptor[] = {
    {"symbolFor", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// SymbolFor方法添加到jsvm-api.md
static JSVM_Value SymbolFor(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value description = nullptr;
    OH_JSVM_CreateStringUtf8(env, "test_demo", 9, &description);
    char buffer[128];
    size_t bufferSize = 128;
    size_t copied = 0;
    OH_JSVM_GetValueStringUtf8(env, description, buffer, bufferSize, &copied);
    JSVM_Value symbol = nullptr;
    OH_JSVM_CreateSymbol(env, description, &symbol);
    JSVM_Value result_symbol = nullptr;
    JSVM_Status status = OH_JSVM_SymbolFor(env, nullptr, 0, &result_symbol);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    JSVM_ValueType valuetypeSymbol;
    OH_JSVM_Typeof(env, result_symbol, &valuetypeSymbol);
    if (valuetypeSymbol == JSVM_SYMBOL && status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_SymbolFor success");
        type = true;
    }
    OH_JSVM_GetBoolean(env, type, &returnValue);
    // 返回结果
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let script: string = `symbolFor()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM symbolFor: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM symbolFor error: %{public}s', error.message);
}
```
