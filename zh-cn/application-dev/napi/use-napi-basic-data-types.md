# 使用Node-API接口创建基本数据类型
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 简介

ArkTS的Number类型是一个双精度64位二进制格式IEEE 754值。只有在-2^53+1到2^53-1范围内（闭区间）的整数才能在不丢失精度的情况下被表示，在超过该取值范围的情况下，需要使用BigInt对应的NPI接口来处理更大范围的整数。

## 基本概念

当使用Node-API接口进行数值类型的创建和获取时，有一些基本概念需要了解：

- **数值类型** 在使用Node-API接口时，可能需要从Node-API模块数值类型转换为ArkTS数值类型值，或者从ArkTS数据类型值转换为Node-API模块数值类型。在进行数据类型转换时，需要注意数据范围是否匹配，以及有无符号整数和双精度数值等区别。
- **错误处理** 在使用这些接口时，需要对可能发生的错误进行适当处理。比如，在创建整数值时可能发生内存分配错误或其他运行时错误，需要使用Node-API提供的错误处理机制来捕获并处理这些错误。
- **ArkTS交互** 在开发过程中，需要考虑如何将创建的数值类型值与ArkTS环境进行交互，包括传递参数、返回值等。

## 场景和功能介绍

以下Node-API函数通常在开发ArkTS的Node-API模块时使用，以便处理数值类型值，帮助开发人员在Node-API模块中和ArkTS数值进行交互：
| 接口 | 描述 |
| -------- | -------- |
| napi_get_value_uint32 | 将ArkTS环境中number类型数据转为Node-API模块中的uint32类型数据。 |
| napi_get_value_int32 | 将ArkTS环境中获取的number类型数据转为Node-API模块中的int32类型数据。 |
| napi_get_value_int64 | 将ArkTS环境中获取的number类型数据转为Node-API模块中的int64类型数据。 |
| napi_get_value_double | 将ArkTS环境中获取的number类型数据转为Node-API模块中的double类型数据。 |
| napi_create_int32 | 将Node-API模块中的int32_t类型转换为ArkTS环境中number类型。 |
| napi_create_uint32 | 将Node-API模块中的uint32_t类型转换为ArkTS环境中number类型。 |
| napi_create_int64 | 将Node-API模块中的int64_t类型转换为ArkTS环境中number类型。 |
| napi_create_double | 将Node-API模块中的double类型转换为ArkTS环境中number类型。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_get_value_uint32

用于从ArkTS环境中获取32位无符号整数值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueUint32(napi_env env, napi_callback_info info)
{
    // 获取传入的数字类型参数
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // 解析传入的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    uint32_t number = 0;
    // 获取传入参数的值中的无符号32位整数
    napi_status status = napi_get_value_uint32(env, argv[0], &number);
    // 如果传递的参数不是数字,将会返回napi_number_expected，设置函数返回nullptr
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    // 创建传入参数无符号32位整数，并传出
    napi_create_uint32(env, number, &result);
    return result;
}
```
<!-- @[napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueUint32: <T>(data: T) => number | undefined;
```
<!-- @[napi_get_value_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = testNapi.getValueUint32<number>(111111111111);
let data = testNapi.getValueUint32<string>("sssss");
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d', value);
// 传入非数字"sssss"时函数返回undefined
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}s', data);
// 传入uint32范围内的数字100时函数返回原数字
hilog.info(0x0000, 'Node-API', 'get_value_uint32_number %{public}d', testNapi.getValueUint32<number>(100));
```
<!-- @[ark_napi_get_value_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_int32

将ArkTS value转为Node-API模块中的int32类型数据。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueInt32(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int32_t result32 = 0;
    // 解析传递的参数
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将前端传过来的参数转为Node-API模块的int32类型
    napi_status status = napi_get_value_int32(env, args[0], &result32);
    // 如果传递的参数不是数字napi_get_value_int32接口将会返回napi_number_expected，设置函数返回nullptr
    if (status != napi_ok) {
        return nullptr;
    }
    // 调用napi_create_int32接口将int32类型的数据转为napi_value返回
    napi_value napiResult32 = nullptr;
    napi_create_int32(env, result32, &napiResult32);
    return napiResult32;
}
```
<!-- @[napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueInt32: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 传入非数字“ss”时函数返回undefined
hilog.info(0x0000, 'Node-API', 'get_value_int32_not_number %{public}s', testNapi.getValueInt32('ss'));
// 传入int32范围内的数字100时函数返回原数字
hilog.info(0x0000, 'Node-API', 'get_value_int32_number %{public}d', testNapi.getValueInt32(100));
// 传入68719476735，此数字的二进制为111111111111111111111111111111111111，在int32类型中此二进制代表数字-1
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(68719476735));
// 大于2的31次-1的数字且不是二进制为111111111111111111111111111111111111这样的在int32中有特殊含义的数字也会溢出，导致数值发生改变，返回值按后32位二进制编码解码
hilog.info(0x0000, 'Node-API', 'get_value_int32_oversize %{public}d', testNapi.getValueInt32(687194767355));
// 传入NAN（not a number）、+Infinity（正无穷）或-Infinity（负无穷），会返回数字0
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_NAN %{public}d', testNapi.getValueInt32(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_+Infinity %{public}d', testNapi.getValueInt32(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int32_number_-Infinity %{public}d', testNapi.getValueInt32(-Infinity));
```
<!-- @[ark_napi_get_value_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_int64

将ArkTS value转为Node-API模块中的int64类型数据。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetValueInt64(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    int64_t result64 = 0;
    // 解析传递的值
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将前端传过来的参数转为Node-API模块的int64类型
    napi_status status = napi_get_value_int64(env, args[0], &result64);
    // 如果传递的参数不是数字, 返回napi_number_expected.
    if (status != napi_ok) {
        return nullptr;
    }
    // 调用napi_create_int64接口将int64类型的数据转为napi_value返回前端
    napi_value napiResult64 = nullptr;
    napi_create_int64(env, result64, &napiResult64);
    return napiResult64;
}
```
<!-- @[napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getValueInt64: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 输入不超过int64表示范围的数字，会返回该数字
hilog.info(0x0000, 'Node-API', 'get_value_int64_number %{public}d', testNapi.getValueInt64(80));
// 传入非数字“ss”，获得函数返回的值应为undefined
hilog.info(0x0000, 'Node-API', 'get_value_int64_not_number %{public}s', testNapi.getValueInt64('sAs'));
// 输入超过int64表示范围的数字会溢出，失去精度，导致输入数字与返回数字不相等
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_oversize %{public}d', testNapi.getValueInt64(9223372036854775809));
// 传入NAN（not a number）、+Infinity（正无穷）或-Infinity（负无穷）接口返回数字0
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_NAN %{public}d', testNapi.getValueInt64(NaN));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_+Infinity %{public}d', testNapi.getValueInt64(+Infinity));
hilog.info(0x0000, 'Node-API', 'get_value_int64_number_-Infinity %{public}d', testNapi.getValueInt64(-Infinity));
```
<!-- @[ark_napi_get_value_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_get_value_double

将ArkTS value转为Node-API模块中的double类型数据。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetDouble(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    double value = 0;
    napi_status status = napi_get_value_double(env, args[0], &value);
    // 传入非数字接口返回napi_number_expected
    if (status != napi_ok) {
        return nullptr;
    }
    napi_value result = nullptr;
    napi_create_double(env, value, &result);
    return result;
}
```
<!-- @[napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getDouble: (value: number | string) => number | undefined;
```
<!-- @[napi_get_value_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
// 输入数字，返回该数字
hilog.info(0x0000, 'Node-API', 'get_value_double_number %{public}d', testNapi.getDouble(80.885));
// 传入非数字，获得函数返回的值应为undefined
hilog.info(0x0000, 'Node-API', 'get_value_double_not_number %{public}s', testNapi.getDouble('sAs'));
```
<!-- @[ark_napi_get_value_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_int32

用于创建一个ArkTS数字（int32类型）的值。

cpp部分代码

```cpp
#include "napi/native_api.h"
static constexpr int INT_NUM_NEG_26 = -26;   // int类型数值-26

static napi_value CreateInt32(napi_env env, napi_callback_info info)
{
    // int32_t是有符号的32位整数类型，表示带有符号的整数，它的范围是从-2^31到2^31 - 1，也就是-2147483648到2147483647
    // 要表示的整数值
    int32_t value = INT_NUM_NEG_26;
    // 创建ArkTS中的int32数字
    napi_value result = nullptr;
    napi_status status = napi_create_int32(env, value, &result);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Failed to create int32 value");
    }
    return result;
}
```
<!-- @[napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createInt32: () => number;
```
<!-- @[napi_create_int32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_int32：' + testNapi.createInt32());
```
<!-- @[ark_napi_create_int32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_uint32

用于创建一个ArkTS数字（uint32类型）的值。

cpp部分代码

```cpp
#include "napi/native_api.h"
static constexpr int INT_NUM_26 = 26;   // int类型数值26

static napi_value CreateUInt32(napi_env env, napi_callback_info info)
{
    // 如果使用 uint32_t类型来定义-26，会发生溢出，溢出时会对结果进行模运算，将负数的二进制补码转换为相应的正数。-26输出4294967270
    // uint32_t是无符号的32位整数类型，只能表示非负整数。它的范围是从0到2 ^32 - 1，即0到4294967295
    // 要表示的整数值
    uint32_t value = INT_NUM_26;
    // 创建ArkTS中的uint32数字
    napi_value result = nullptr;
    napi_status status = napi_create_uint32(env, value, &result);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Failed to create uint32 value");
    }
    return result;
}
```
<!-- @[napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createUInt32: () => number;
```
<!-- @[napi_create_uint32_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_uint32: ' + testNapi.createUInt32());
```
<!-- @[ark_napi_create_uint32](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_int64

用于创建一个ArkTS数字（int64类型）的值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateInt64(napi_env env, napi_callback_info info)
{
    // 要表示的整数值
    int64_t value = 2147483648;
    // 使用给定数值创建一个ArkTS number，仅能准确表示范围从-2^53 + 1到2^53 - 1（闭区间）的整数
    // 如果想表示的数值超过了2^53，请使用napi_create_bigint64接口
    napi_value result = nullptr;
    napi_status status = napi_create_int64(env, value, &result);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Failed to create int64 value");
    }
    return result;
}
```
<!-- @[napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createInt64: () => number;
```
<!-- @[napi_create_int64_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_int64: ' + testNapi.createInt64());
```
<!-- @[ark_napi_create_int64](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

### napi_create_double

用于创建一个ArkTS数字（double类型）的值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateDouble(napi_env env, napi_callback_info info)
{
    double value = 1.234;
    // 创建ArkTS中的double数字
    napi_value result = nullptr;
    napi_status status = napi_create_double(env, value, &result);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Failed to create double value");
    }
    return result;
}
```
<!-- @[napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createDouble: () => number;
```
<!-- @[napi_create_double_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag','Test Node-API napi_create_double: ' + testNapi.createDouble());
```
<!-- @[ark_napi_create_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBasicDataTypes/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
