# 使用Node-API其他实用接口
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## 简介

Node-API接口提供了一些实用接口，可以帮助开发者更好地进行Node-API相关开发。

## 基本概念

- **模块加载：** 在Node-API模块中，模块是指包含特定功能的ArkTS文件，通过import导入lib共享库中的模块。了解Node-API模块中的加载机制以及模块之间的依赖关系对于理解node_api_get_module_file_name接口的使用很有帮助。
- **文件路径和URL：** node_api_get_module_file_name返回的是加载项的绝对路径的URL。
- **比较ArkTS值严格相等：** 比较两个ArkTS值是否严格相等。严格相等比较不会进行类型转换，它要求两个值的类型和值完全相同才会返回true。
- **处理异步操作：** 通过Libuv可以实现异步操作，避免阻塞主线程，使得程序可以同时执行多个任务而不会出现阻塞现象。
- **实现事件循环：** Libuv提供了事件循环机制，可以处理事件、触发回调函数，并管理事件队列，使得Node-API模块能够实现事件驱动的编程模型。

## 场景和功能介绍

| 接口 | 描述 |
| -------- | -------- |
| node_api_get_module_file_name | 获取加载项加载位置的绝对路径。 |
| napi_strict_equals | 在某些情况下，希望确保两个值不仅具有相同的值，还具有相同的类型。例如，如果正在处理一些需要特定类型的数据结构或算法，使用napi_strict_equals可以确保数据的一致性。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### node_api_get_module_file_name

用于获取加载项的绝对路径。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetModuleFileName(napi_env env, napi_callback_info info)
{
    // 声明一个const char类型的指针变量file，用于存储模块绝对路径
    const char *file = nullptr;
    napi_value value = nullptr;
    // 获取当前模块的绝对路径，并将结果存储在file变量中
    napi_status status = node_api_get_module_file_name(env, &file);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get module file name");
        return nullptr;
    }
    // 创建一个包含绝对路径的napi_value类型的字符串
    napi_create_string_utf8(env, file, NAPI_AUTO_LENGTH, &value);
    return value;
}
```

接口声明

```ts
// index.d.ts
export const getModuleFileName: () => string | undefined;
```

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let filename = testNapi.getModuleFileName();
hilog.info(0x0000, 'testTag', 'Test Node-API node_api_get_module_file_name:%{public}s', filename);
```

### napi_strict_equals

判断给定的两个ArkTS value是否严格相等。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value StrictEquals(napi_env env, napi_callback_info info)
{
    // 接受两个入参
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_strict_equals接口判断给定的两个ArkTS value是否严格相等
    bool result = true;
    napi_status status = napi_strict_equals(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_strict_equals fail");
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
export const strictEquals: (lhs: string, rhs: string | number) => boolean | undefined;
```

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

try {
  let lhs = "123";
  let rhs = "123";
  let str = "456";
  let num = 123;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, rhs));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, str));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, num));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_strict_equals error: %{public}s', error.message);
}
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
