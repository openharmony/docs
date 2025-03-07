# 使用Node-API接口进行object相关开发

## 简介

使用Node-API接口进行object相关开发，处理ArkTS对象的基本操作的功能，例如创建对象、获取原型、冻结和密封对象，检查对象的类型等。这些操作是在处理ArkTS对象时非常常见的，提供了一种与ArkTS对象交互的方式。

## 基本概念

在Node-API接口开发中，经常需要定义和操作对象。例如，创建一个API接口，该接口接受一个对象作为输入参数，对该对象执行某些操作，并返回一个结果对象。在这个过程中，需要确保接口的定义清晰、规范，并且与对象的属性和方法相兼容。

- **接口（API）**：接口定义了组件之间的交互协议，包括输入参数、输出结果以及可能的错误处理。通过接口，组件可以相互调用和交换数据，而无需了解对方的内部实现细节。
- **对象（Object）**：在ArkTS，对象是一种复合数据类型，允许存储多个不同类型的值作为一个单独的实体。对象是属性和方法的集合。属性是与对象相关联的值，而方法则是对象可以执行的操作。

## 场景和功能介绍

以下Node-API接口主要用于操作和管理ArkTS对象，使用场景介绍：
| 接口 | 描述 |
| -------- | -------- |
| napi_get_prototype | 当需要获取一个ArkTS对象的原型时，可以使用这个接口。通过这个接口可以在C/C++中获取到这个原型对象。 |
| napi_create_object | 在Node-API模块中创建一个默认的ArkTS对象。 |
| napi_object_freeze | 当需要确保一个对象不会被修改时（immutable），可以使用这个接口来冻结该对象，使其属性不可更改。 |
| napi_object_seal | 类似于napi_object_freeze，napi_object_seal用于密封给定的对象，使其属性不可添加或删除，但可以修改属性的值。 |
| napi_typeof | 在处理传入的ArkTS值时，可以使用这个接口来获取其类型，以便进行相应的处理。 |
| napi_instanceof | 当需要在Node-API模块中确定一个对象是否为特定构造函数的实例时，可以使用这个接口。 |
| napi_type_tag_object | 可以将指针的特定值与ArkTS对象关联起来，这对于一些自定义的内部对象标记非常有用。 |
| napi_check_object_type_tag | 使用此接口可以检查给定的对象上是否关联了特定类型的标记。 |
| napi_create_symbol | 创建一个ArkTS Symbol对象。 |
| napi_create_external | 用于创建一个ArkTS外部对象，该对象可以用于将C/C++中的自定义数据结构或对象传递到ArkTS中，并且可以在ArkTS中访问其属性和方法。 |
| napi_get_value_external | 用于获得napi_create_external创建的绑定了外部数据的ArkTS值，此函数可以在ArkTS和C/C++之间传递数据。 |

这些接口为开发人员提供了在Node-API模块中处理ArkTS对象的灵活性和功能性，可以实现从创建对象到管理对象属性以及类型检查等多种操作。

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_get_prototype

可以获得给定ArkTS对象的prototype。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetPrototype(napi_env env, napi_callback_info info)
{
    // 获取并解析传参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    napi_value result = nullptr;
    // 获取此对象的原型对象，将结果返回到napi_value类型的变量result中
    napi_get_prototype(env, args[0], &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getPrototype: (object: Object) => Object;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
// 定义一个类
class Person {
  // 属性
  name: string;
  age: number;
  // 构造函数
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
// 创建类的实例
const person = new Person('Alice', 30);
// 传入实例对象，获取该对象的原型
let applePrototype = testNapi.getPrototype(person);
// 判断通过testNapi.getPrototype()函数获取到的原型是不是apple的原型
// 在DevEco Studio 4.1及以后的版本中，由于ArkTS没有原型的概念，因此尝试进行原型赋值或相关操作时，将会触发错误提示'Prototype assignment is not supported (arkts-no-prototype-assignment)'，以下代码需在ts文件中执行
if (applePrototype === Person.prototype) {
  hilog.info(0x0000, 'Node-API', 'get_prototype_success');
} else {
  hilog.info(0x0000, 'Node-API', 'get_prototype_fail');
}
```

### napi_create_object

用于在Node-API模块中创建一个空的ArkTS对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

napi_value NewObject(napi_env env, napi_callback_info info)
{
    napi_value object = nullptr;
    // 创建一个空对象
    napi_create_object(env, &object);
    // 设置对象的属性
    napi_value name = nullptr;
    // 设置属性名为"name"
    napi_create_string_utf8(env, "name", NAPI_AUTO_LENGTH, &name);
    napi_value value = nullptr;
    // 设置属性值为"Hello from Node-API!"
    napi_create_string_utf8(env, "Hello from Node-API!", NAPI_AUTO_LENGTH, &value);
    // 将属性设置到对象上
    napi_set_property(env, object, name, value);
    return object;
}
```

接口声明

```ts
// index.d.ts
export const createObject: () => { name: string };
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  const myObject = testNapi.createObject();
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_object: %{public}s', myObject.name);
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_object errorCode: %{public}s, errorMessage: %{public}s', error.code, error.message);
}
```

### napi_object_freeze

用于冻结给定的ArkTS对象。冻结对象后，无法再向对象添加新的属性或方法，也无法修改已有属性或方法的值。

cpp部分代码

```cpp
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value ObjectFreeze(napi_env env, napi_callback_info info)
{
    // 接受一个ArkTS侧传入的object
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    // 调用接口napi_object_freeze将传入的object冻结
    napi_value objFreeze = argv[0];
    napi_status status = napi_object_freeze(env, objFreeze);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_freeze success");
    }
    // 将冻结后的object传回ArkTS侧
    return objFreeze;
}
```

接口声明

```ts
// index.d.ts
export interface Obj {
  data: number
  message: string
}
export const objectFreeze: (objFreeze: Object) => Obj;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_object_seal

封闭一个对象后，无法向其添加新的属性，也无法删除或修改现有属性的可配置性。但是，可以继续修改已有属性的值。

cpp部分代码

```cpp
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value ObjectSeal(napi_env env, napi_callback_info info)
{
    // 接受一个ArkTS侧传入的object
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 调用接口napi_object_seal将传入的object封闭，使其无法添加新的属性
    napi_value objSeal = argv[0];
    napi_status status = napi_object_seal(env, objSeal);
    if (status == napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API napi_object_seal success");
    }
    // 将封闭后的object传回ArkTS侧
    return objSeal;
}
```

接口声明

```ts
// index.d.ts
export interface Obj {
  data: number
  message: string
  id: number
}
export const objectSeal : (objSeal: Object) => Obj;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  class Obj {
    data: number = 0
    message: string = ""
    // 可选属性
    address?: number = 0
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

### napi_typeof

获取给定ArkTS value的ArkTS Type。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiTypeOf(napi_env env, napi_callback_info info)
{
    // 接受一个入参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 调用napi_typeof判断传入ArkTS参数类型
    napi_valuetype valueType;
    napi_status status = napi_typeof(env, args[0], &valueType);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_typeof fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回。
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

接口声明

```ts
// index.d.ts
export const napiTypeOf : <T>(value: T) => string | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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
  const addNum = (a: number, b: number): number => a * b;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(addNum));
  let varBigint = BigInt("1234567890123456789012345678901234567890");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_typeof: %{public}s', testNapi.napiTypeOf(varBigint));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_typeof error: %{public}s', error.message);
}
```

### napi_instanceof

用于检查一个对象是否是指定构造函数的实例。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiInstanceOf(napi_env env, napi_callback_info info)
{
    // 接受两个入参
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_instanceof接口判断给定object是否为给定constructor的实例
    bool result = true;
    napi_status status = napi_instanceof(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_instanceof fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const napiInstanceOf: (date: Object, construct: Object) => boolean | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_type_tag_object

使用类型标签type_tag来标记ArkTS对象，后续可以更精确地识别ArkTS对象。

### napi_check_object_type_tag

验证一个ArkTS对象是否带有特定类型标签。

类型标签提供了一种在Node-API模块和ArkTS对象之间建立强类型关联的机制，使得原生代码能够更准确地识别和处理特定的ArkTS对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

#define NUMBERINT_FOUR 4
// 定义一个静态常量napi_type_tag数组存储类型标签
static const napi_type_tag TagsData[NUMBERINT_FOUR] = {
    {0x9e4b2449547061b3, 0x33999f8a6516c499},
    {0x1d55a794c53a726d, 0x43633f509f9c944e},
    // 用于表示无标签或默认标签
    {0, 0},
    {0x6a971439f5b2e5d7, 0x531dc28a7e5317c0},
};

static napi_value SetTypeTagToObject(napi_env env, napi_callback_info info)
{
    // 获取函数调用信息和参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取索引数字转换为napi_value
    int32_t index = 0;
    napi_get_value_int32(env, args[1], &index);
    // 给参数（对象）设置类型标签
    napi_status status = napi_type_tag_object(env, args[0], &TagsData[index]);
    if (status != napi_ok) {
        napi_throw_error(env, "Reconnect error", "napi_type_tag_object failed");
        return nullptr;
    }
    // 将bool结果转换为napi_value并返回
    napi_value result = nullptr;
    napi_get_boolean(env, true, &result);
    return result;
}

static napi_value CheckObjectTypeTag(napi_env env, napi_callback_info info)
{
    // 获取函数调用信息和参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取索引数字转换为napi_value
    int32_t index = 0;
    napi_get_value_int32(env, args[1], &index);
    // 检查对象的类型标签 
    bool checkResult = true;
    napi_check_object_type_tag(env, args[0], &TagsData[index], &checkResult);
    // 将bool结果转换为napi_value并返回
    napi_value checked = nullptr;
    napi_get_boolean(env, checkResult, &checked);

    return checked;
}
```

接口声明

```ts
// index.d.ts
export const setTypeTagToObject: (obj: Object, index: number) => boolean | void;
export const checkObjectTypeTag: (obj: Object, index: number) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
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

### napi_create_external

创建包装自定义的C/C++对象并将其公开给ArkTS代码。这种情况下，我们可以使用napi_create_external来创建一个包含指向自定义对象的指针的Node-API值，以便让ArkTS代码能够访问和操作该对象。

cpp部分代码

```cpp
#include <cstdlib>
#include <string>
#include "napi/native_api.h"

// 用于释放外部数据的回调函数
void finalizeCallback(napi_env env, void *data, void *hint) {
    // 释放外部数据
    free(data);
}

static napi_value GetExternalType(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取参数的数据类型
    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    napi_value returnValue = nullptr;
    if (valueType == napi_external) {
        // 如果数据类型是napi_external,则返回true
        napi_get_boolean(env, true, &returnValue);
    } else {
        napi_get_boolean(env, false, &returnValue);
    }
    return returnValue;
}

static napi_value CreateExternal(napi_env env, napi_callback_info info)
{
    // 设置外部数据大小为10
    const size_t dataSize = 10;
    // 分配外部数据
    void *data = malloc(dataSize);
    // 初始化外部数据
    memset(data, 0, dataSize);
    napi_value result = nullptr;
    // 返回带有外部数据的对象
    napi_status status = napi_create_external(env, data, finalizeCallback, nullptr, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, " Node-API Failed to create external data");
        return nullptr;
    }
    return result;
}
```

接口声明

```ts
// index.d.ts
export const createExternal: () => Object;
export const getExternalType: (externalData: Object) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
const externalData = testNapi.createExternal();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_external:%{public}s', testNapi.getExternalType(externalData));
```

### napi_get_value_external

napi_create_external可以创建包装自定义的C/C++对象并将其公开给ArkTS代码，而napi_get_value_external就是用来获得napi_create_external所创建的外部对象的。

cpp部分代码

```cpp
#include "napi/native_api.h"

static int external = 5; 
static napi_value GetValueExternal(napi_env env, napi_callback_info info)
{
    // 创建外部数据
    int* data = &external;
    napi_value setExternal = nullptr;
    napi_create_external(env, data, nullptr, nullptr, &setExternal);
    // 获得外部数据的值
    void *getExternal;
    napi_get_value_external(env, setExternal, &getExternal);
    // 返回获得到的外部数据
    napi_value result = nullptr;
    napi_create_int32(env, *(int *)getExternal, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getValueExternal: () => number;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
hilog.info(0x0000, 'Node-API', 'get_value_external:%{public}d', testNapi.getValueExternal());
```

### napi_create_symbol

用于创建一个新的Symbol。Symbol是一种特殊的数据类型，用于表示唯一的标识符。与字符串或数字不同，符号的值是唯一的，即使两个符号具有相同的描述，它们也是不相等的。符号通常用作对象属性的键，以确保属性的唯一性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateSymbol(napi_env env, napi_callback_info info)
{
    napi_value result = nullptr;
    const char *des = "only";
    // 使用napi_create_string_utf8创建描述字符串
    napi_create_string_utf8(env, des, NAPI_AUTO_LENGTH, &result);
    napi_value returnSymbol = nullptr;
    // 创建一个symbol类型，并返回
    napi_create_symbol(env, result, &returnSymbol);
    return returnSymbol;
}
```

接口声明

```ts
// index.d.ts
export const createSymbol : () => symbol;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
let varSymbol = testNapi.createSymbol();
hilog.info(0x0000, 'Node-API', 'createSymbol:%{public}s', typeof varSymbol);
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
