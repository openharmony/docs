# 使用Node-API接口进行ArrayBuffer相关开发

## 简介

ArrayBuffer是ArkTS中的一种数据类型，用于表示通用的、固定长度的原始二进制数据缓冲区。它提供了一种在ArkTS中有效地表示和操作原始二进制数据的方式。

## 基本概念

- **ArrayBuffer**：ArrayBuffer对象用来表示一个通用的、固定长度的原始二进制数据缓冲区。不能直接操作ArrayBuffer的内容，而是需要包装成TypedArray对象或DataView对象来读写。ArrayBuffer常用于处理大量的二进制数据，如文件、网络数据包等。
- **生命周期和内存管理**：在使用Node-API处理ArrayBuffer时，需注意创建的arrayBufferPtr生命周期由引擎管理，不允许用户自己delete，否则会double free。

## 场景和功能介绍

以下Node-API接口通常在Node-API模块中操作ArrayBuffer类型的数据。以下是一些可能的使用场景：

| 接口 | 描述 |
| -------- | -------- |
| napi_is_arraybuffer | 检查一个值是否为ArrayBuffer，以确保正在处理正确的数据类型。需要注意的是，此函数只能判断一个值是否为ArrayBuffer，而不能判断一个值是否为TypedArray。如果需要判断一个值是否为TypedArray，可以使用napi_is_typedarray函数。 |
| napi_get_arraybuffer_info | 获取给定的ArrayBuffer对象的相关信息，包括数据指针和数据长度。 |
| napi_detach_arraybuffer | 在某些情况下，当需要频繁地访问ArrayBuffer的底层数据缓冲区时，将其分离可以提高性能。分离后可以直接在C/C++中操作数据，而无需通过Node-API接口进行数据访问。 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已经被分离。 |
| napi_create_arraybuffer | 用于在Node-API模块中创建一个具有指定字节长度的ArkTS ArrayBuffer对象。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_is_arraybuffer

判断给定ArkTS value是否为ArrayBuffer。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsArrayBuffer(napi_env env, napi_callback_info info)
{
    // 接受一个入参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_is_arraybuffer接口判断给定入参是否为ArrayBuffer数据
    bool result = false;
    napi_status status = napi_is_arraybuffer(env, args[0], &result);  
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_arraybuffer fail");
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
export const isArrayBuffer: <T>(arrayBuffer: T) => boolean | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  let value = new ArrayBuffer(1);
  let data = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer: %{public}s', testNapi.isArrayBuffer(value));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer: %{public}s', testNapi.isArrayBuffer(data));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer error: %{public}s', error.message);
}
```

### napi_get_arraybuffer_info

获取ArrayBuffer的底层数据缓冲区和长度。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetArrayBufferInfo(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 检查参数是否为ArrayBuffer
    bool isArrayBuffer = false;
    napi_is_arraybuffer(env, args[0], &isArrayBuffer);
    if (!isArrayBuffer) {
        napi_throw_type_error(env, nullptr, "Argument must be an ArrayBuffer");
        return nullptr;
    }

    void *data = nullptr;
    size_t byteLength = 0;
    // 获取ArrayBuffer的底层数据缓冲区和长度
    napi_status status = napi_get_arraybuffer_info(env, args[0], &data, &byteLength);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get ArrayBuffer info");
        return nullptr;
    }
    // 创建结果对象
    napi_value result = nullptr;
    napi_create_object(env, &result);
    // 创建数据缓冲区的字节长度属性
    napi_value byteLengthValue = nullptr;
    napi_create_uint32(env, byteLength, &byteLengthValue);
    napi_set_named_property(env, result, "byteLength", byteLengthValue);
    napi_value bufferData;
    napi_create_arraybuffer(env, byteLength, &data, &bufferData);
    napi_set_named_property(env, result, "buffer", bufferData);
    return result;
}
```

接口声明

```ts
// index.d.ts
export class ArrayBufferInfo {
  byteLength: number;
  buffer: Object;
}
export const getArrayBufferInfo: (data: ArrayBuffer) => ArrayBufferInfo | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

const buffer = new ArrayBuffer(10);
hilog.info(0x0000, 'testTag', 'Test Node-API get_arrayBuffer_info:%{public}s ', JSON.stringify(testNapi.getArrayBufferInfo(buffer)));
```

### napi_detach_arraybuffer

分离给定ArrayBuffer的底层数据。

### napi_is_detached_arraybuffer

判断给定的ArrayBuffer是否已被分离。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value DetachedArrayBuffer(napi_env env, napi_callback_info info)
{
    // 调用napi_detach_arraybuffer接口分离给定ArrayBuffer的底层数据
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value arrayBuffer = args[0];
    napi_detach_arraybuffer(env, arrayBuffer);
    // 将分离后的arraybuffer传出去
    return arrayBuffer;
}

static napi_value IsDetachedArrayBuffer(napi_env env, napi_callback_info info)
{
    // 调用napi_is_detached_arraybuffer判断给定的arraybuffer是否已被分离
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value arrayBuffer = args[0];
    bool result = false;
    napi_is_detached_arraybuffer(env, arrayBuffer, &result);
    // 将返回值通过napi_get_boolean接口转成napi_value传出去做打印
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const detachedArrayBuffer: (buffer:ArrayBuffer) => ArrayBuffer;
export const isDetachedArrayBuffer: (arrayBuffer: ArrayBuffer) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  const bufferArray = new ArrayBuffer(8);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer one: %{public}s', testNapi.isDetachedArrayBuffer(bufferArray));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer two: %{public}s ', testNapi.isDetachedArrayBuffer(testNapi.detachedArrayBuffer(bufferArray)));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer error: %{public}s', error.message);
}
```

### napi_create_arraybuffer

用于在C/C++中创建一个具有指定字节长度的ArkTS ArrayBuffer对象，如果调用者想要直接操作缓冲区，则可以选择将底层缓冲区返回给调用者。要从ArkTS写入此缓冲区，需要创建类型化数组或DataView对象。

> **注意**
>
> napi_create_arraybuffer在byte_length为0或超大值时，data返回值将为nullptr。因此在对data进行使用前，有必要对其进行判空。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateArrayBuffer(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value result = nullptr;
    // 解析传递的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int32_t value;
    size_t length;
    // 将ArkTS侧传递的参数转换为size_t类型，作为napi_create_arraybuffer的参数
    napi_get_value_int32(env, argv[0], &value);
    length = size_t(value);
    void *data;
    // 创建一个新的ArrayBuffer
    napi_create_arraybuffer(env, length, &data, &result);
    if (data != nullptr) {
        // 确保安全后才能使用data进行操作
    }
    // 返回ArrayBuffer
    return result;
}
```

接口声明

```ts
// index.d.ts
export const createArrayBuffer: (size: number) => ArrayBuffer;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_arraybuffer:%{public}s', testNapi.createArrayBuffer(10).toString());
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
