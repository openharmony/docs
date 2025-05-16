# 使用Node-API接口关联数据，使其生命周期与当前环境的生命周期相关联

## 简介

在Node-API模块中，我们可以使用Node-API接口将特定数据与当前的环境相关联，并在需要时检索该数据。

## 基本概念

在Node-API中的关联数据是指将自定义的C++数据结构的生命周期与当前环境的生命周期相关联，这意味着只要当前运行环境存在，关联数据就会保持有效。

## 场景和功能介绍

以下接口可以帮助我们在Node-API模块中更方便地管理对象实例所需的状态信息、引用计数或其他自定义数据，他们的使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_set_instance_data | 绑定与当前运行的环境相关联的数据项。 |
| napi_get_instance_data | 检索与当前运行的环境相关联的数据项。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_set_instance_data

将需要绑定的数据与当前运行的环境相关联。

cpp部分代码

```cpp
#include <cstdlib>
#include "napi/native_api.h"

// 定义一个结构来存储实例数据
struct InstanceData {
    int32_t value;
};

// 对象被释放时的回调函数，用于清理实例数据
void FinalizeCallback(napi_env env, void *finalize_data, void *finalize_hint)
{
    if (finalize_data) {
        InstanceData *data = reinterpret_cast<InstanceData *>(finalize_data);
        // 释放内存，清除指针指向地址
        delete (data);
        *(InstanceData **)finalize_data = nullptr;
    }
}

static napi_value SetInstanceData(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int32_t instanceDataValue;
    napi_get_value_int32(env, argv[0], &instanceDataValue);
    InstanceData *instanceData = new InstanceData;
    instanceData->value = instanceDataValue;
    // 调用napi_set_instance_data将实例数据关联到Node-API环境，并指定FinalizeCallback函数
    napi_status status = napi_set_instance_data(env, instanceData, FinalizeCallback, nullptr);
    bool success = true;
    napi_value result;
    if (status == napi_ok) {
        napi_get_boolean(env, success, &result);
    }
    return result;
}
```

接口声明

```ts
// index.d.ts
export const setInstanceData: (data: number) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
let data = 5;
let value = testNapi.setInstanceData(data);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_instance_data:%{public}s', value);
```

### napi_get_instance_data

检索出与当前运行的环境相关联的数据项。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetInstanceData(napi_env env, napi_callback_info info) {
    InstanceData *resData = nullptr;
    // napi_get_instance_data获取之前想关联的数据项
    napi_get_instance_data(env, (void **)&resData);
    napi_value result;
    napi_create_int32(env, resData->value, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getInstanceData: () => number;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
let data = 5;
testNapi.setInstanceData(data);
let value = testNapi.getInstanceData();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_instance_data:%{public}d', value);
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
