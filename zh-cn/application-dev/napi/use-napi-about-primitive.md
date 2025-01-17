# 使用Node-API接口进行primitive类相关开发

## 简介

在使用Node-API接口时，开发人员可以实现在Node-API模块中与ArkTS对象的交互，并进行数据转换和获取特定对象的操作，它们在不同的场景中发挥着重要的作用，使开发人员能够更灵活地处理ArkTS值和对象。

## 基本概念

在使用Node-API操作ArkTS对象时，有一些基本概念需要了解：

- **ArkTS值到C/C++类型的转换：** 在Node-API模块中，可以使用Node-API函数将ArkTS值转换为C/C++的数据类型，如将ArkTS数值转换为C/C++的整数、将ArkTS字符串转换为C/C++的字符数组等。同样，也可以将C/C++的数据类型转换为ArkTS值，以便将结果返回给ArkTS代码。

## 场景和功能介绍

以下接口用于从C/C++代码中与ArkTS进行交互，传递数据并执行操作，它们的使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_coerce_to_bool | 用于将给定的ArkTS value强转成ArkTS boolean值。 |
| napi_coerce_to_number | 用于将给定的ArkTS value强转成ArkTS number。 |
| napi_coerce_to_object | 用于将给定的ArkTS value强转成ArkTS Object。 |
| napi_coerce_to_string | 用于将给定的ArkTS value强转成ArkTS string。 |
| napi_get_boolean | 用于根据给定的C boolean值，获取ArkTS boolean值。 |
| napi_get_value_bool | 用于根据给定的ArkTS boolean值，获取等价的C/C++布尔值。 |
| napi_get_global | 用于获取全局ArkTS对象，以便在C/C++中访问和操纵全局对象。 |
| napi_get_null | 用于获取ArkTS null。 |
| napi_get_undefined | 用于获取ArkTS undefined。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_coerce_to_bool

用于将给定的ArkTS value强转成ArkTS boolean值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CoerceToBool(napi_env env, napi_callback_info info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将传入的值转换为布尔值
    napi_value result = nullptr;
    napi_coerce_to_bool(env, args[0], &result);
    //返回强转之后的ArkTS boolean值
    return result;
}
```

接口声明

```ts
// index.d.ts
export const coerceToBool: <T>(data: T) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.coerceToBool<number>(0);
let str = testNapi.coerceToBool<string>('111111111');
let obj = new Object();
let res = testNapi.coerceToBool<Object>(obj);
let result = testNapi.coerceToBool<null>(null);
// false
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', value);
// true
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', str);
// true
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', res);
// false
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_bool:%{public}s', result);
```

### napi_coerce_to_number

用于将给定的ArkTS value强转成ArkTS number。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CoerceToNumber(napi_env env, napi_callback_info info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将传入的值转换为number值
    napi_value result = nullptr;
    napi_coerce_to_number(env, args[0], &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const coerceToNumber: <T>(data: T) => number;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.coerceToNumber<string>('2556');
let str = testNapi.coerceToNumber<string>('sssss');
let bool = testNapi.coerceToNumber<boolean>(true);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', value);
// 返回的为NAN
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', str);
// 返回的是1
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_number:%{public}d', bool);
```

### napi_coerce_to_object

用于将给定的ArkTS value强转成ArkTS Object。

cpp部分代码：

```cpp
#include "napi/native_api.h"

static napi_value CoerceToObject(napi_env env, napi_callback_info info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value obj = nullptr;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将传入的值转换为Object值
    napi_coerce_to_object(env, args[0], &obj);
    return obj;
}
```

接口声明

```ts
// index.d.ts
export const coerceToObject: <T>(data: T) => Object;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.coerceToObject<string>('222222');
let result = testNapi.coerceToObject<number>(111);
hilog.info(0x0000, 'testTag', 'Node-API coerceToObject:%{public}s.', typeof result);
if (typeof value === 'object') {
  hilog.info(0x0000, 'testTag', 'Node-API The value is an object.');
} else {
  hilog.info(0x0000, 'testTag', 'Node-API The value is not an object.');
}
```

### napi_coerce_to_string

用于将给定的ArkTS value强转成ArkTS string。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CoerceToString(napi_env env, napi_callback_info info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将传入的值转换为string
    napi_value str = nullptr;
    napi_coerce_to_string(env, args[0], &str);
    return str;
}
```

接口声明

```ts
// index.d.ts
export const coerceToString: <T>(data: T) => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.coerceToString<number>(212);
let obj = new Object();
let res = testNapi.coerceToString<Object>(obj);
let bool = testNapi.coerceToString<boolean>(false);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', typeof res);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_coerce_to_string:%{public}s', bool);
```

### napi_get_boolean

用于根据给定的C boolean值，获取等价的ArkTS Boolean对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetBoolean(napi_env env, napi_callback_info info)
{
    // 传入两个参数并解析
    size_t argc = 2;
    napi_value argv[2];
    napi_valuetype data, value;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 判断两个参数类型值
    napi_typeof(env, argv[0], &data);
    napi_typeof(env, argv[1], &value);

    napi_value returnValue = nullptr;
    // 判断两个类型值是否相等,获取结果的布尔值
    napi_get_boolean(env, data == value, &returnValue);
    // 返回结果
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const getBoolean: <T>(data: T, value: String) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.getBoolean<number>(1, '1');
let data = testNapi.getBoolean<string>('sss', '1');
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', value);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_boolean:%{public}s', data);
```

### napi_get_value_bool

使用这个函数将ArkTS中的布尔值转为等价的C布尔值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueBool(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    bool bool_c = false;
    napi_status status = napi_get_value_bool(env, args[0], &bool_c);
    if (status == napi_boolean_expected) {
        // 如果napi_get_value_bool成功会返回napi_ok，如果传入一个非布尔值则会返回napi_boolean_expected
        return nullptr;
    }
    napi_value boolNapi = nullptr;
    napi_get_boolean(env, bool_c, &boolNapi);
    return boolNapi;
}
```

接口声明

```ts
// index.d.ts
export const getValueBool: (value: boolean | string) => boolean | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

// 分别传入布尔值和非布尔值检测接口,传入布尔值将返回原布尔值,传入其他类型返回undefined
hilog.info(0x0000, 'Node-API', 'get_value_bool_not_bool %{public}s', testNapi.getValueBool('你好123'));
hilog.info(0x0000, 'Node-API', 'get_value_bool_true %{public}s', testNapi.getValueBool(true));
hilog.info(0x0000, 'Node-API', 'get_value_bool_false %{public}s', testNapi.getValueBool(false));
```

### napi_get_global

用于获取全局ArkTS对象。该函数的主要作用是获取表示ArkTS全局对象的napi_value，使得C/C++模块能够与ArkTS运行时的全局对象进行交互。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetGlobal(napi_env env, napi_callback_info info)
{
    napi_value global = nullptr;
    // 获取global对象
    napi_get_global(env, &global);
    return global;
}
```

接口声明

```ts
// index.d.ts
export const getGlobal: () => Object;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let globalObj = testNapi.getGlobal();
// 判断获取的global是否具有global的自身属性
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_global:%{public}s', globalObj.hasOwnProperty!("undefined"));
```

### napi_get_null

用于获取ArkTS中的null。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetNull(napi_env env, napi_callback_info info)
{
    napi_value nullValue = nullptr;
    napi_get_null(env, &nullValue);
    return nullValue;
}
```

接口声明

```ts
// index.d.ts
export const getNull: () => null;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.getNull();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_null:%{public}s', value);
```

### napi_get_undefined

用于获取ArkTS中的undefined。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetUndefined(napi_env env, napi_callback_info info)
{
    // 获取并解析传进的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_value value = nullptr;
    napi_get_undefined(env, &value);
    // 判断传入参数的类型与undefined值的类型是否一致
    bool isEqual = false;
    napi_strict_equals(env, args[0], value, &isEqual);
    // 参数与undefined值相等
    napi_value result = nullptr;
    // 返回判断类型之后的结果，相等返回为true，不等则为false
    napi_get_boolean(env, isEqual, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getUndefined: (value: undefined) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let data: undefined = undefined;
let value = testNapi.getUndefined(data);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_undefined:%{public}s', value);
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
