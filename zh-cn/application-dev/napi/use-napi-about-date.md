# 使用Node-API接口进行Date相关开发

## 简介

Node-API中date相关接口用于处理ArkTS Date对象，并在Node-API模块和ArkTS代码之间进行日期数据的转换和处理。这对于在Node-API模块中处理时间和日期相关逻辑非常有用。

## 基本概念

在Node-API的中，ArkTS Date对象的数据表示从UTC时间1970年1月1日0时0分0秒起至现在的总毫秒数。

ArkTS Date对象提供了一种在ArkTS中表示和操作日期和时间的方式。它们允许您创建表示特定时刻的日期对象，执行各种日期和时间相关的计算（如添加或减去时间间隔），以及格式化日期为字符串以供显示。

在Node-API中，通过提供与Date对象交互的函数，Node-API模块能够更紧密地与ArkTS环境集成，执行更复杂的日期和时间相关操作。

## 场景和功能介绍

以下Node-API函数通常在开发Node-API模块中与ArkTS的Date对象进行交互时使用，来处理和操作日期数据。以下是一些可能的使用场景：
| 接口 | 描述 |
| -------- | -------- |
| napi_create_date | 在需要根据当前系统时间或特定计算生成一个Date对象时，可通过使用此接口创建表示这些时间的ArkTS Date对象，然后将其传递给ArkTS代码进行进一步处理。 |
| napi_get_date_value | 在Node-API模块中接收到一个ArkTS的Date对象，并且需要获取其对应的时间戳或日期值时，可以使用此接口。|
| napi_is_date | 在需要确定一个ArkTS对象是否为Date对象时，可使用此接口判断给定的值是否为Date对象。例如，在接收函数参数时，需要验证参数是否为Date对象以确保正确的数据类型。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应的C++及ArkTS相关代码进行展示。

### napi_create_date

通过一个C++的double数据创建ArkTS的Date对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateDate(napi_env env, napi_callback_info info)
{
    // 获取传入的Unix Time Stamp时间
    double value = 1501924876711;
    // 调用napi_create_date接口将double值转换成表示日期时间的ArkTS对象，并放入returnValue中
    napi_value returnValue = nullptr;
    napi_create_date(env, value, &returnValue);
    return returnValue;
}
```
<!-- @[napi_create_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createDate: () => Date;
```
<!-- @[napi_create_date_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_date: %{public}s', testNapi.createDate().toString());
```
<!-- @[ark_napi_create_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->

### napi_get_date_value

获取给定ArkTS Date对应的C++ double值。

cpp部分代码

```cpp
#include <hilog/log.h>
#include "napi/native_api.h"

static napi_value GetDateValue(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 获取传入的Unix Time Stamp时间
    double value = 0;
    napi_status status = napi_get_date_value(env, args[0], &value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_date_value fail");
        return nullptr;
    }

    // 将获取到的Unix Time Stamp时间打印
    OH_LOG_INFO(LOG_APP, "Node-API gets unix time stamp is:%{public}lf.", value);

    // 把转换后的Unix Time Stamp时间创建成ArkTS double数值，并放入returnValue中
    napi_value returnValue = nullptr;
    napi_create_double(env, value, &returnValue);
    return returnValue;
}
```
<!-- @[napi_get_date_value](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getDateValue: (date: Date) => number | void;
```
<!-- @[napi_get_date_value_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  const date = new Date();
  hilog.info(0x0000, 'testTag', 'Node-API: output the Unix Time Stamp: %{public}d', date.getTime());
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_date_value: %{public}d', testNapi.getDateValue(date));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_date_value error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_date_value](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->

### napi_is_date

判断给定ArkTS value是否为ArkTS Date对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsDate(napi_env env, napi_callback_info info)
{
    // 接受一个入参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 调用napi_is_date接口判断给定入参是否为Date数据
    bool result = false;
    napi_status status = napi_is_date(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_date fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const isDate: <T>(date: T) => boolean | void;
```
<!-- @[napi_is_date_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  let now: Date = new Date();
  let date = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_date: %{public}s', testNapi.isDate(now));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_date: %{public}s', testNapi.isDate(date));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_date error: %{public}s', error.message);
}
```
<!-- @[ark_napi_is_date](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
