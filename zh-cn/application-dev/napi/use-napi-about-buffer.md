# 使用Node-API接口进行buffer相关开发

## 简介

在ArkTS中，Buffer是一种用于处理二进制数据的数据类型。

## 基本概念

使用Node-API接口进行buffer相关开发时，使用Buffer对象与ArkTS代码之间进行二进制数据的有效交互，以便在Node-API模块创建、操纵和传递Buffer对象到ArkTS，从而处理和传递二进制数据，比如文件I/O、网络传输等。

- **Buffer对象**：用于表示一段二进制数据的对象。
- **外部Buffer**：在Node-API模块中创建的Buffer，可以与现有的数据关联起来而不需要复制数据到新的Buffer中。

## 场景和功能使用

以下这些接口用于有效地与ArkTS层进行交互，这使Node-API模块能够更好地处理ArkTS层的二进制数据，比如处理文件I/O、网络传输等操作：
| 接口 | 描述 |
| -------- | -------- |
| napi_create_buffer | 用于创建并获取一个指定大小的ArkTS Buffer。 |
| napi_create_buffer_copy | 用于创建并获取一个指定大小的ArkTS Buffer，并以给定的入参数据对buffer的缓冲区进行初始化。 |
| napi_create_external_buffer | 用于创建并获取一个指定大小的ArkTS Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 |
| napi_get_buffer_info | 获取ArkTS Buffer底层数据缓冲区及其长度。 |
| napi_is_buffer | 判断给定ArkTS value是否为Buffer对象。 |
| napi_create_external_arraybuffer | 用于分配一个附加有外部数据的ArkTS ArrayBuffer。外部ArrayBuffer是一个特殊类型的ArrayBuffer，它持有对外部数据的引用而不实际拥有数据存储。|

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_create_buffer

此接口用于创建Buffer对象。Buffer对象是用于在Node-API模块中操作二进制数据的一种特殊类型。

cpp部分代码

```cpp
#include <string>
#include "napi/native_api.h"

static napi_value CreateBuffer(napi_env env, napi_callback_info info)
{
    std::string str("CreateBuffer");
    void *bufferPtr = nullptr;
    size_t bufferSize = str.size();
    napi_value buffer = nullptr;
    // 调用napi_create_buffer接口创建并获取一个指定大小的ArkTS Buffer
    napi_create_buffer(env, bufferSize, &bufferPtr, &buffer);
    // 将字符串str的值复制到buffer的内存中
    strcpy((char *)bufferPtr, str.data());
    return buffer;
}
```

接口声明

```ts
// index.d.ts
export const createBuffer: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_buffer: %{public}s', testNapi.createBuffer().toString());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_buffer error');
}
```

### napi_create_buffer_copy

本接口是Node-API中用于创建并复制数据到Buffer对象的函数。它可以在Node-API模块中创建一个新的Buffer对象，并将指定的数据复制到该Buffer对象中。

cpp部分代码

```cpp
#include <string>
#include "hilog/log.h"
#include "napi/native_api.h"

static napi_value CreateBufferCopy(napi_env env, napi_callback_info info)
{
    // 要copy的内容
    std::string str("CreateBufferCopy");
    napi_value buffer = nullptr;
    // 调用napi_create_buffer_copy接口创建buffer并将str的内容copy到buffer
    void* resultData = nullptr;
    napi_create_buffer_copy(env, str.size(), str.data(), &resultData, &buffer);
    OH_LOG_INFO(LOG_APP, "Node-API resultData is : %{public}s.", resultData);
    return buffer;
}
```

接口声明

```ts
// index.d.ts
export const createBufferCopy: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_buffer_copy: %{public}s', testNapi.createBufferCopy().toString());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_buffer_copy error');
}
```

### napi_create_external_buffer

当希望在ArkTS中使用现有的Node-API模块内存块，而不需要额外的拷贝时，可以使用napi_create_external_buffer。这将允许ArkTS层直接访问并操作该内存，避免额外的内存分配和拷贝操作。

cpp部分代码

```cpp
#include <malloc.h>
#include <string>
#include "napi/native_api.h"

// 回调函数，用于释放内存
void FinalizeCallback(napi_env env, void *data, void *hint)
{
    if (data == nullptr) {
        return;
    }
    free(data);
    data = nullptr;
}

static napi_value CreateExternalBuffer(napi_env env, napi_callback_info info)
{
    // 创建一个字符串
    std::string str("CreateExternalBuffer");
    // 在堆上分配内存，大小为字符串的长度
    void* data = malloc(str.size());
    // 将字符串复制到分配的内存中
    strcpy((char *)(data), (char*)(str.data()));
    // 使用napi_create_external_buffer接口创建并获取一个指定大小buffer
    napi_value buffer = nullptr;
    napi_create_external_buffer(env, str.size(), data, FinalizeCallback, nullptr, &buffer);
    return buffer;
}
```

接口声明

```ts
// index.d.ts
export const createExternalBuffer: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_external_buffer: %{public}s', testNapi.createExternalBuffer()
    .toString());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_external_buffer error');
}
```

### napi_get_buffer_info

在ArkTS中需要对Buffer对象中的数据执行特定的操作时，可以使用此接口来获取指向数据的指针和数据长度。这样可以在Node-API模块直接对数据进行操作，而无需进行数据的拷贝。

cpp部分代码

```cpp
#include <string>
#include "napi/native_api.h"

static napi_value GetBufferInfo(napi_env env, napi_callback_info info)
{
    // 创建一个字符串
    std::string str("GetBufferInfo");
    napi_value buffer = nullptr;
    void *bufferPtr = nullptr;
    size_t bufferSize = str.size();
    napi_create_buffer(env, bufferSize, &bufferPtr, &buffer);
    strcpy((char *)bufferPtr, str.data());

    // 获取Buffer的信息
    void *tmpBufferPtr = nullptr;
    size_t bufferLength = 0;
    napi_get_buffer_info(env, buffer, &tmpBufferPtr, &bufferLength);

    // 创建一个新的ArkTS字符串来保存Buffer的内容并返出去
    napi_value returnValue = nullptr;
    napi_create_string_utf8(env, (char*)tmpBufferPtr, bufferLength, &returnValue);
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const getBufferInfo: () => string;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_buffer_info: %{public}s', testNapi.getBufferInfo().toString());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_buffer_info error');
}
```

### napi_is_buffer

判断给定ArkTS value是否为Buffer对象。

cpp部分代码

```cpp
#include <string>
#include "napi/native_api.h"

static napi_value IsBuffer(napi_env env, napi_callback_info info)
{
    // 创建一个Buffer对象
    std::string str = "buffer";
    napi_value buffer = nullptr;
    napi_create_buffer(env, strlen(str.data()), (void **)(str.data()), &buffer);

    // 调用napi_is_buffer接口判断创建的对象是否为buffer
    bool result = false;
    napi_is_buffer(env, buffer, &result);
    // 将结果返回出去
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const isBuffer: () => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_buffer: %{public}s', JSON.stringify(testNapi.isBuffer()));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_buffer error');
}
```

### napi_create_external_arraybuffer

分配一个附加有外部数据的ArkTS ArrayBuffer。

cpp部分代码

```cpp
#include "napi/native_api.h"

typedef struct {
    uint8_t *data;
    size_t length;
} BufferData;

void FinalizeCallback(napi_env env, void *finalize_data, void *finalize_hint)
{
    // 获取终结时的数据
    BufferData *bufferData = static_cast<BufferData *>(finalize_data);

    // 执行清理操作，比如释放资源
    delete[] bufferData->data;
    delete bufferData;
}

napi_value CreateExternalArraybuffer(napi_env env, napi_callback_info info)
{
    // 创建一个有五个元素的C++数组
    uint8_t *dataArray = new uint8_t[5]{1, 2, 3, 4, 5};
    napi_value externalBuffer = nullptr;
    BufferData *bufferData = new BufferData{dataArray, 5};

    // 使用napi_create_external_arraybuffer创建一个外部Array Buffer对象，并指定终结回调函数
    napi_status status =
        napi_create_external_arraybuffer(env, dataArray, 5, FinalizeCallback, bufferData, &externalBuffer);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Node-API napi_create_external_arraybuffer fail");
        return nullptr;
    }
    napi_value outputArray;
    // 使用napi_create_typedarray创建一个Array对象，并将externalBuffer对象作为参数传入
    status = napi_create_typedarray(env, napi_int8_array, 5, externalBuffer, 0, &outputArray);
    if (status != napi_ok) {
        // 处理错误
        napi_throw_error(env, nullptr, "Node-API napi_create_typedarray fail");
        return nullptr;
    }
    return outputArray;
}
```

接口声明

```ts
// index.d.ts
export const createExternalArraybuffer: () => ArrayBuffer | void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Node-API createExternalArraybuffer: %{public}s',
           JSON.stringify(testNapi.createExternalArraybuffer()));
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
