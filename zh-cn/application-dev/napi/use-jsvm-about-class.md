# 使用JSVM进行class相关开发

## 简介

使用JSVM-API接口进行class相关开发，处理JavaScript中的类，例如定义类、构造实例等。

## 基本概念

在使用JSVM-API接口进行class相关开发时，需要理解以下基本概念：

- **类**：类是用于创建对象的模板。它提供了一种封装数据和行为的方式，以便于对数据进行处理和操作。类在JavaScript中是建立在原型（prototype）的基础上的，并且还引入了一些类独有的语法和语义。
- **实例**：实例是通过类创建具体的对象。类定义了对象的结构和行为，而实例则是类的具体表现。通过实例化类，我们可以访问类中定义的属性和方法，并且每个实例都具有自己的属性值。

## 接口说明

| 接口                | 功能说明                           |
| ------------------- | ---------------------------------- |
| OH_JSVM_NewInstance   | 通过给定的构造函数，构建一个实例|
| OH_JSVM_GetNewTarget  | 获取构造函数调用的new.target|
| OH_JSVM_DefineClass   | 用于在JavaScript中定义一个类，并与对应的C类进行封装和交互。它提供了创建类的构造函数、定义属性和方法的能力，以及在C和JavaScript之间进行数据交互的支持|
| OH_JSVM_Wrap           | 在JavaScript对象中封装原生实例。稍后可以使用OH_JSVM_Unwrap()检索原生实例|
| OH_JSVM_Unwrap         | 使用OH_JSVM_Wrap()检索先前封装在JavaScript对象中的原生实例|
| OH_JSVM_RemoveWrap     | 检索先前封装在JavaScript对象中的原生实例并移除封装|
|OH_JSVM_DefineClassWithOptions | 定义一个具有给定类名、构造函数、属性和回调处理程序、父类的JavaScript类，并根据传入了DefineClassOptions来决定是否需要为所定义的Class设置属性代理、预留internal-field槽位、为class作为函数进行调用时设置函数回调。|

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### OH_JSVM_NewInstance

通过给定的构造函数，构建一个实例。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
通过给定的构造函数，构建一个实例。
// NewInstance注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = NewInstance},
};
static JSVM_CallbackStruct *method = param;
// NewInstance方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"newInstance", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_NewInstance的样例方法
static JSVM_Value NewInstance(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用OH_JSVM_NewInstance接口，实例化一个对象，将这个对象返回
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_NewInstance(env, args[0], 1, &args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM API TEST RESULT: FAILED");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: PASS");
    }
    return result;
}
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
// 通过import的方式，引入Native能力。
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

用于获取构造函数的new.target值。在JavaScript中，new.target是一个特殊的元属性，用于在构造函数中判断是否通过new关键字调用了该构造函数。

### OH_JSVM_DefineClass

用于在JavaScript中定义一个类，并与对应的C类进行封装和交互。它提供了创建类的构造函数、定义属性和方法的能力，以及在C和JavaScript之间进行数据交互的支持

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// 自定义类结构体
struct DefineObject {
    std::string name;
    int32_t age;
    JSVM_Ref wrapper_;
};
static thread_local JSVM_Ref g_ref = nullptr;
// 创建实例
struct DefineObject *defineObject = new struct DefineObject();
JSVM_Value New(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value newTarget;
    OH_JSVM_GetNewTarget(env, info, &newTarget);
    if (newTarget != nullptr) {
        OH_LOG_INFO(LOG_APP, "NAPI MyObject::New newTarget != nullptr");
        // 使用`new MyObject(...)`调用方式
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

// 获取封装后的c++自定义结构中的数据方法
napi_value GetObj(napi_env env) {
    std::string str = "{\"name\": \"" + defineObject->name + "\",\"age\": " + std::to_string(defineObject->age) + "}";
    napi_value jsResult;
    napi_create_string_utf8(env, str.c_str(), NAPI_AUTO_LENGTH, &jsResult);
    return jsResult;
}

// 封装c++中的自定义数据结构
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

需要将[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)中的RunJsVm方法改动如下：

```cpp
    // hello.cpp
    // 将JSVM开发流程文档中defineClass方法的预留位置的代码更改为如下内容
    if (strcmp(sourceCodeStr.c_str(), "defineClass") == 0) {
        JSVM_Value obj;
        DefineClass(env, obj);
        nResult = GetObj(nEnv);
    } 
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
// 通过import的方式，引入Native能力。
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

在JavaScript对象中封装原生实例。稍后可以使用OH_JSVM_Unwrap()检索原生实例

### OH_JSVM_Unwrap

使用OH_JSVM_Wrap()检索先前封装在JavaScript对象中的原生实例

### OH_JSVM_RemoveWrap

检索先前封装在JavaScript对象中的原生实例并移除封装

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// WrapObject、RemoveWrap注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = WrapObject},
    {.data = nullptr, .callback = RemoveWrap},
};
static JSVM_CallbackStruct *method = param;
// WrapObject、RemoveWrap方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"wrapObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"removeWrap", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT}
};
// OH_JSVM_GetNewTarget、OH_JSVM_DefineClass、OH_JSVM_Wrap、OH_JSVM_Unwrap、OH_JSVM_RemoveWrap的样例方法
// 表示是否调用了deref_item函数
static bool deref_item_called = false;

// 自定义类结构体Object
struct Object {
    std::string name;
    int32_t age;
};
struct Object *obj = new struct Object();

// 定义一个回调函数
static void DerekItem(JSVM_Env env, void *data, void *hint) {
    OH_LOG_INFO(LOG_APP, "JSVM deref_item");
    (void)hint;
}

static JSVM_Value WrapObject(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM wrap");
    // 设置Object属性
    obj->name = "lilei";
    obj->age = 18;
    // 获取回调信息中的参数数量和将要被封装的值
    size_t argc = 1;
    JSVM_Value toWrap = nullptr;
    OH_JSVM_GetCbInfo(env, info, &argc, &toWrap, nullptr, nullptr);
    // 将自定义结构Object封装
    OH_JSVM_Wrap(env, toWrap, reinterpret_cast<void *>(obj), DerekItem, NULL, NULL);
    struct Object *data;
    struct Object *data1;
    OH_JSVM_Unwrap(env, toWrap, reinterpret_cast<void **>(&data));
    OH_LOG_INFO(LOG_APP, "JSVM name: %{public}s", data->name.c_str());
    OH_LOG_INFO(LOG_APP, "JSVM age: %{public}d", data->age);
    //检索先前封装的object，并移除封装
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

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
// 通过import的方式，引入Native能力。
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

### OH_JSVM_DefineClassWithOptions
**Note:** 传入的父类class必须是通过OH_JSVM_DefineClass系列接口创建出来的，不然会被视为无效参数，返回JSVM_INVALID_ARG错误码。
目前支持以下的DefineClassOptions:
- JSVM_DEFINE_CLASS_NORMAL: 按正常模式创建Class。默认缺省状态为JSVM_DEFINE_CLASS_NORMAL状态。
- JSVM_DEFINE_CLASS_WITH_COUNT: 为所创建的Class预留interfield槽位。
- JSVM_DEFINE_CLASS_WITH_PROPERTY_HANDLER: 为所创建的Class设置监听拦截属性以及设置作为函数调用时回调函数
#### cpp代码
```c++
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
    double num1, num2;
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
    char *buffer = new char[capacity];
    size_t copy_length = 0;
    OH_JSVM_GetValueStringUtf8(jsvm_env, js_string, buffer, capacity, &copy_length);
    std::string str(buffer);
    delete[] buffer;
    return str;
}

JSVM_Value Run(JSVM_Env env, const char *s)
{
    // 1. 将const char*转换成JS_String。
    JSVM_Value str;
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, s, JSVM_AUTO_LENGTH, &str));
    // 2. 将JS_String转换成JS_Script。
    JSVM_Script script;
    OH_JSVM_CompileScript(jsvm_env, str, nullptr, JSVM_AUTO_LENGTH,   false, nullptr, &script);
    // 3. 执行JS_Script。
    JSVM_Value result;
    OH_JSVM_RunScript(jsvm_env, script, &result);
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
    JSVM_Value fooVal = Str(env, "bar");
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
    if (g_call_as_function_flag == true &&
    g_set_named_property_flag == true &&
    g_call_as_constructor_flag == true &&
    g_properties_flag == true) {
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
#### 样例JS

const char *srcCallNative = R"JS(testDefineClassWithOptions();)JS";
#### 执行结果

在LOG中输出下面的结果：
Run OH_JSVM_DefineClassWithOptions: Success
