# 使用JSVM-API接口进行array相关开发

## 简介

使用JSVM-API接口进行array相关开发时，调用相关接口可以在JSVM模块中直接操作和处理JavaScript中的数组。

## 基本概念

使用JSVM-API接口进行数组（array）相关开发时，涉及的基本概念主要包括数组的创建、访问、修改、遍历以及与数组相关的操作。这些概念对于理解如何在JSVM模块中与JavaScript数组交互非常重要。以下是一些关键概念：

- **数组的创建**：在JSVM模块中需要创建一个新的JavaScript数组，可以使用提供的OH_JSVM_CreateArray接口创建数组，将数组传递给JavaScript层。
- **数组相关操作**：在JSVM模块中通过对应的接口获取JavaScript数组的长度、检索指定索引处的元素以及设置指定索引处的元素值，从而实现JSVM模块与JavaScript数组的交互。
- **TypedArray**：JavaScript中的TypedArray是一种用来描述二进制数据的类数组数据视图，可以简单理解为一种指定元素类型的数组，TypedArray没有直接构造器，但是可以用它的子类构造器构造TypedArray类型的数据。TypedArray的子类有：Int8Array、Uint8Array、Uint8ClampedArray、Int16Array、Int32Array等。
- **DataView**：DataView是JavaScript中的一种视图，是可以从ArrayBuffer对象中读写多种数值类型的底层接口。
- **ArrayBuffer**：ArrayBuffer是固定长度的二进制数据缓冲区。

## 接口说明

| 接口                         | 功能说明                                   |
| ---------------------------- | ------------------------------------------ |
|OH_JSVM_CreateArray | 创建一个新的 JavaScript 数组对象 |
|OH_JSVM_CreateArrayWithLength | 创建一个指定长度的 JavaScript 数组对象 |
|OH_JSVM_CreateTypedarray | 在现有的 ArrayBuffer 上创建一个 JavaScript TypedArray 对象,TypedArray 对象在底层数据缓冲区上提供类似数组的视图，其中每个元素都具有相同的底层二进制标量数据类型 |
|OH_JSVM_CreateDataview | 在现有的 ArrayBuffer 上创建一个 JavaScript DataView 对象,DataView 对象在底层数据缓冲区上提供类似数组的视图 |
|OH_JSVM_GetArrayLength | 返回 Array 对象的长度 |
|OH_JSVM_GetTypedarrayInfo | 获取 TypedArray（类型化数组）对象的信息 |
|OH_JSVM_GetDataviewInfo | 获取 Dataview 对象的信息 |
|OH_JSVM_IsArray | 判断一个 JavaScript 对象是否为 Array 类型对象|
|OH_JSVM_SetElement | 在给定对象的指定索引处设置元素 |
|OH_JSVM_GetElement | 获取给定对象指定索引处的元素 |
|OH_JSVM_HasElement | 若给定对象的指定索引处拥有属性，获取该元素 |
|OH_JSVM_DeleteElement | 尝试删除给定对象的指定索引处的元素 |
|OH_JSVM_IsDataview | 判断一个 JavaScript 对象是否为 Dataview 类型对象 |
|OH_JSVM_IsTypedarray | 判断一个 JavaScript 对象是否为 Typedarray 类型对象 |

## 使用示例

以下样例代码的基础代码已在jsvm-api.md实现，样例的注册回调、方法别名、样例方法都需要添加到jsvm-api.md。

### OH_JSVM_CreateArray

创建一个新的JavaScript数组对象。

cpp部分代码

```cpp
// CreateArray注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArray},
};
static JSVM_CallbackStruct *method = param;
// CreateArray方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static int DIFF_VALUE_FIVE = 5;
// OH_JSVM_CreateArray的样例方法
static JSVM_Value CreateArray(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "array";
    // 创建一个空数组
    JSVM_Value array = nullptr;
    OH_JSVM_CreateArray(env, &array);
    // 对创建的数组进行赋值
    for (int i = 0; i < DIFF_VALUE_FIVE; i++) {
        JSVM_Value element;
        OH_JSVM_CreateInt32(env, i, &element);
        OH_JSVM_SetElement(env, array, i, element);
    }
    return array;
}
```

ArkTS侧示例代码

```ts
let script: string = `
  function testCreateArray() {
    return createArray();
  }
  testCreateArray()
`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateArray: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateArray error: %{public}s', error.message);
}
```

### OH_JSVM_CreateArrayWithLength

创建一个指定长度的JavaScript数组对象。

cpp部分代码：

```cpp
// CreateArrayWithLength注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArrayWithLength},
};
static JSVM_CallbackStruct *method = param;
// CreateArrayWithLength方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArrayWithLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateArrayWithLength的样例方法
static JSVM_Value CreateArrayWithLength(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "array";
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value result = nullptr;
    // 解析传递的参数OH_JSVM_GetCbInfo
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // 获取传递的数组长度
    int32_t length;
    OH_JSVM_GetValueInt32(env, argv[0], &length);
    // 使用OH_JSVM_CreateArrayWithLength创建传递固定长度的数组
    JSVM_Status status = OH_JSVM_CreateArrayWithLength(env, length, &result);
    if (status == JSVM_OK) {
        // 给创建的数组设置值
        for (int32_t i = 0; i < length; i++) {
            JSVM_Value value;
            OH_JSVM_CreateInt32(env, i, &value);
            OH_JSVM_SetElement(env, result, i, value);
        }
    }
    return result;
}
```

ArkTS侧示例代码

```ts
let num = 7;
let script: string = `
  function testCreateArrayWithLength(num) {
    return createArrayWithLength(num);
  }
  testCreateArrayWithLength(${num})
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateArrayWithLength: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateArrayWithLength error: %{public}s', error.message);
}
```

### OH_JSVM_CreateTypedarray

在现有的ArrayBuffer上创建一个JavaScript TypedArray对象,TypedArray对象在底层数据缓冲区上提供类似数组的视图，其中每个元素都具有相同的底层二进制标量数据类型。

cpp部分代码

```cpp
// CreateTypedArray注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateTypedArray},
};
static JSVM_CallbackStruct *method = param;
// CreateTypedArray方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createTypedArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateTypedarray的样例方法
static int DIFF_VALUE_THREE = 3;
static JSVM_Value CreateTypedArray(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "typearray";
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int32_t typeNum;
    OH_JSVM_GetValueInt32(env, args[0], &typeNum);
    JSVM_TypedarrayType arrayType;
    // 用于存储每个元素的大小
    size_t elementSize = 0;
    // 转换为JSVM_TypedarrayType类型
    arrayType = static_cast<JSVM_TypedarrayType>(typeNum);
    switch (typeNum) {
    case JSVM_INT8_ARRAY:
    case JSVM_UINT8_ARRAY:
    case JSVM_UINT8_CLAMPED_ARRAY:
        elementSize = sizeof(int8_t);
        break;
    case JSVM_INT16_ARRAY:
    case JSVM_UINT16_ARRAY:
        elementSize = sizeof(int16_t);
        break;
    case JSVM_INT32_ARRAY:
    case JSVM_UINT32_ARRAY:
        elementSize = sizeof(int32_t);
        break;
    case JSVM_FLOAT32_ARRAY:
        elementSize = sizeof(float);
        break;
    case JSVM_FLOAT64_ARRAY:
        elementSize = sizeof(double);
        break;
    case JSVM_BIGINT64_ARRAY:
    case JSVM_BIGUINT64_ARRAY:
        elementSize = sizeof(int64_t);
        break;
    default:
        // 默认创建JSVM_INT8_ARRAY类型
        arrayType = JSVM_INT8_ARRAY;
        elementSize = sizeof(int8_t);
        break;
    }
    size_t length = DIFF_VALUE_THREE;
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value typedArray = nullptr;
    void *data;
    // 创建一个ArrayBuffer
    OH_JSVM_CreateArraybuffer(env, length * elementSize, (void **)&data, &arrayBuffer);
    // 根据给定类型创建TypedArray
    OH_JSVM_CreateTypedarray(env, arrayType, length, arrayBuffer, 0, &typedArray);
    return typedArray;
}
```

ArkTS侧示例代码

```ts
try {
  // INT8_ARRAY
  let type = napitest.TypedArrayTypes["INT8_ARRAY"];
  let script: string = `
    createTypedArray(${type})
    `;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray error: %{public}s', error.message);
}
try {
  // INT32_ARRAY
  let type = napitest.TypedArrayTypes["INT32_ARRAY"];
  let str: string = `createTypedArray(${type})`;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray error: %{public}s', error.message);
}
```

### OH_JSVM_CreateDataview

在现有的ArrayBuffer上创建一个JavaScript DataView对象，DataView对象在底层数据缓冲区上提供类似数组的视图。

cpp部分代码

```cpp
// CreateDataView注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDataView},
};
static JSVM_CallbackStruct *method = param;
// CreateDataView方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_CreateDataview的样例方法
static int DIFF_VALUE_FOUR = 4;
static int DIFF_VALUE_TWELVE = 12;
static JSVM_Value CreateDataView(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value result = nullptr;
    // DataView的字节长度
    size_t byteLength = DIFF_VALUE_TWELVE;
    // 字节偏移量
    size_t byteOffset = DIFF_VALUE_FOUR;
    // 获取回调函数的参数信息
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将参数转换为对象类型
    OH_JSVM_CoerceToObject(env, args[0], &arrayBuffer);
    // 创建一个数据视图对象，并指定字节长度和字节偏移量
    JSVM_Status status = OH_JSVM_CreateDataview(env, byteLength, arrayBuffer, byteOffset, &result);
    if (status != JSVM_OK) {
        return nullptr;
    }
    // 获取DataView的指针和长度信息
    uint8_t *data = nullptr;
    size_t length = 0;
    // 为DataView赋值
    for (size_t i = 0; i < length; i++) {
        data[i] = static_cast<uint8_t>(i + 1);
    }
    int32_t infoType;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);
    size_t returnLength;
    JSVM_Value returnArrayBuffer = nullptr;
    size_t returnOffset;
    enum InfoType { BYTE_LENGTHE, ARRAY_BUFFERE, BYTE_OFFSET };
    // 获取dataview信息
    OH_JSVM_GetDataviewInfo(env, result, &returnLength, (void **)&data, &returnArrayBuffer, &returnOffset);
    JSVM_Value returnResult = nullptr;
    switch (infoType) {
    case BYTE_LENGTHE:
        g_data_type = "int";
        JSVM_Value len;
        OH_JSVM_CreateInt32(env, returnLength, &len);
        returnResult = len;
        break;
    case ARRAY_BUFFERE:
        bool isArraybuffer;
        OH_JSVM_IsArraybuffer(env, returnArrayBuffer, &isArraybuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArraybuffer, &isArray);
        returnResult = isArray;
        break;
    case BYTE_OFFSET:
        g_data_type = "int";
        JSVM_Value offset;
        OH_JSVM_CreateInt32(env, returnOffset, &offset);
        returnResult = offset;
        break;
    default:
        break;
    }
    return returnResult;
}
```

ArkTS侧示例代码

```ts
try {
  let BYTE_LENGTGH = 0;
  let str: string = `
  createDataView(new ArrayBuffer(16), ${BYTE_LENGTGH})
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createDataView len: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createDataView error: %{public}s', error.message);
}
try {
  let IS_ARRAYBUFFER = 1;
  let str: string = `
  createDataView(new ArrayBuffer(16), ${IS_ARRAYBUFFER})
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createDataView is buffer: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createDataView error: %{public}s', error.message);
}
try {
  let BYTE_OFFSET = 2;
  let str: string = `
  createDataView(new ArrayBuffer(16), ${BYTE_OFFSET})
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createDataView offset: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createDataView error: %{public}s', error.message);
}
```

### OH_JSVM_GetArrayLength

返回Array对象的长度。

cpp部分代码

```cpp
// GetArrayLength注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetArrayLength},
};
static JSVM_CallbackStruct *method = param;
// GetArrayLength方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getArrayLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetArrayLength的样例方法
static JSVM_Value GetArrayLength(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "int";
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_Value result = nullptr;
    uint32_t length;
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 检查参数是否为数组
    bool isArray = false;
    OH_JSVM_IsArray(env, args[0], &isArray);
    if (!isArray) {
        OH_LOG_INFO(LOG_APP, "JSVM Argument must be an array");
        return nullptr;
    }
    OH_JSVM_GetArrayLength(env, args[0], &length);
    // 创建返回值
    OH_JSVM_CreateInt32(env, length, &result);
    OH_LOG_INFO(LOG_APP, "JSVM length: %{public}d", length);
    return result;
}
```

ArkTS侧示例代码

```ts
let data =  '[0, 1, 2, 3, 4, 5]';
let str: string = `
  getArrayLength(${data})
  `;
try {
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetArrayLength: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetArrayLength error: %{public}s', error.message);
}
```

### OH_JSVM_GetTypedarrayInfo

获取TypedArray（类型化数组）对象的信息。

cpp部分代码

```cpp
// GetTypedArrayInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetTypedArrayInfo},
};
static JSVM_CallbackStruct *method = param;
// GetTypedArrayInfo方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getTypedArrayInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetTypedarrayInfo的样例方法
static JSVM_Value GetTypedArrayInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取并解析参数，第一个参数为需要获得的信息的TypedArray类型数据，第二个参数为需要获得的信息类型的枚举值
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    // 将第二个参数转为int32类型便于比较
    int32_t infoTypeParam;
    OH_JSVM_GetValueInt32(env, args[1], &infoTypeParam);
    // 定义枚举类型与ArkTs侧枚举类型infoType顺序含义一致
    enum InfoType { INFO_TYPE, INFO_LENGTH, INFO_ARRAY_BUFFER, INFO_BYTE_OFFSET };
    void *data;
    JSVM_TypedarrayType type;
    size_t byteOffset, length;
    JSVM_Value arrayBuffer = nullptr;
    // 调用接口OH_JSVM_GetTypedarrayInfo获得TypedArray类型数据的信息
    OH_JSVM_GetTypedarrayInfo(env, args[0], &type, &length, &data, &arrayBuffer, &byteOffset);
    
    JSVM_Value result = nullptr;
    // 根据属性名，返回TypedArray对应的属性值
    switch (infoTypeParam) {
    case INFO_TYPE:
        // 如果传入的参数是int8类型的TypedArray数据，它的类型（type）为JSVM_INT8_ARRAY
        JSVM_Value int8_type;
        OH_JSVM_GetBoolean(env, type == JSVM_INT8_ARRAY, &int8_type);
        result = int8_type;
        break;
    case INFO_LENGTH:
        g_data_type = "int";
        // TypedArray中的元素数
        JSVM_Value jsvmLength;
        OH_JSVM_CreateInt32(env, length, &jsvmLength);
        result = jsvmLength;
        break;
    case INFO_BYTE_OFFSET:
        g_data_type = "int";
        // TypedArray数组的第一个元素所在的基础原生数组中的字节偏移量
        JSVM_Value jsvmOffset;
        OH_JSVM_CreateInt32(env, byteOffset, &jsvmOffset);
        result = jsvmOffset;
        break;
    case INFO_ARRAY_BUFFER:
        // TypedArray下的ArrayBuffer
        bool isArrayBuffer;
        OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
        result = isArray;
        break;
    default:
        break;
    }
    return result;
}
```

ArkTS侧示例代码

```ts
try {
  // is JSVM_INT8_ARRAY
  let str: string = `
  getTypedArrayInfo(new Int8Array(3), 0)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo is JSVM_INT8_ARRAY: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // is JSVM_INT8_ARRAY
  let str: string = `
  getTypedArrayInfo(new Int16Array(3), 0)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo is JSVM_INT8_ARRAY: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // length
  let str: string = `
  getTypedArrayInfo(new Int8Array(5), 1)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo length: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // is_arraybuffer
  let str: string = `
  getTypedArrayInfo(new Int8Array(5), 2)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo is_arraybuffer: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // byteoffset
  let str: string = `
  getTypedArrayInfo(new Int8Array(1), 3)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo byteoffset: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
```

### OH_JSVM_GetDataviewInfo

获取Dataview对象的信息。

cpp部分代码

```cpp
// GetDataViewInfo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDataViewInfo},
};
static JSVM_CallbackStruct *method = param;
// GetDataViewInfo方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDataViewInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetDataviewInfo的样例方法
static JSVM_Value GetDataViewInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};

    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 将第二个参数转为int32类型的数字
    int32_t infoType;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);

    size_t byteLength;
    void *data;
    JSVM_Value arrayBuffer = nullptr;
    size_t byteOffset;
    // 定义枚举类型与ArkTs侧枚举类型infoType顺序含义一致
    enum infoTypeEnum { BYTE_LENGTHE, ARRAY_BUFFERE, BYTE_OFFSET };
    // 获取dataview信息
    OH_JSVM_GetDataviewInfo(env, args[0], &byteLength, &data, &arrayBuffer, &byteOffset);
    JSVM_Value result = nullptr;
    switch (infoType) {
    case BYTE_LENGTHE:
        g_data_type = "int";
        // 返回查询DataView的长度
        JSVM_Value len;
        OH_JSVM_CreateInt32(env, byteLength, &len);
        result = len;
        break;
    case ARRAY_BUFFERE:
        // 判断DataView的Info里的arraybuffer是否为arraybuffer
        bool isArrayBuffer;
        OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
        result = isArray;
        break;
    case BYTE_OFFSET:
        g_data_type = "int";
        // 返回查询DataView的偏移量
        JSVM_Value offset;
        OH_JSVM_CreateInt32(env, byteOffset, &offset);
        result = offset;
        break;
    default:
        break;
    }
    return result;
}
```

ArkTS侧示例代码

```ts
try {
  // bytelength
  let script: string = `getDataViewInfo(new DataView(new Int8Array([2,5]).buffer), 0)`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo bytelength: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // is arraybuffer
  let data = `'a'`;
  let isarraybuffer = '1';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo is arraybuffer: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // is arraybuffer
  let data = 'new DataView(new Int8Array([2,5,3]).buffer)';
  let isarraybuffer = '1';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo is arraybuffer: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // byte_offset
  let data = 'new DataView(new Int8Array([2,5,3]).buffer)';
  let isarraybuffer = '2';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo byte_offset: %{public}d', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
```

### OH_JSVM_IsArray

判断一个JavaScript对象是否为Array类型对象。

cpp部分代码

```cpp
// IsArray注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsArray},
};
static JSVM_CallbackStruct *method = param;
// IsArray方法别名，TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_IsArray的样例方法
static JSVM_Value IsArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    OH_JSVM_IsArray(env, args[0], &result);
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    return returnValue;
}
```

ArkTS侧示例代码

```ts
let data = '[1, 2, 3, 4, 5]';
let script: string = `
   isArray(${data})
 `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "IsArray: %{public}s", result);
} catch (error) {
  hilog.error(0x0000, "JSVM", "IsArray: %{public}s", error.message);
}
```

### OH_JSVM_SetElement

在给定对象的指定索引处设置元素。

cpp部分代码

```cpp
// SetElement注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetElement},
};
static JSVM_CallbackStruct *method = param;
// SetElement方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"setElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_SetElement的样例方法
static int DIFF_VALUE_THREE = 3;
static JSVM_Value SetElement(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "array";
    size_t argc = DIFF_VALUE_THREE;
    JSVM_Value args[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    OH_JSVM_SetElement(env, args[0], index, args[2]);
    return args[0];
}
```

ArkTS侧示例代码

```ts
let script: string = `
  setElement(3)
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM setElement 0: %{public}d', result[0]);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM setElement 1: %{public}d', result[1]);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM setElement 2: %{public}d', result[2]);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM setElement 3: %{public}s', result[3]);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM setElement error: %{public}s', error.message);
}
```

### OH_JSVM_GetElement

获取给定对象指定索引处的元素。

cpp部分代码

```cpp
// GetElement注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetElement},
};
static JSVM_CallbackStruct *method = param;
// GetElement方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"getElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_GetElement的样例方法
static JSVM_Value GetElement(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取请求元素的索引值
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // 获取请求索引位置的元素值并存储在result中
    JSVM_Value result = nullptr;
    OH_JSVM_GetElement(env, args[0], index, &result);
    // 获取返回结果类型，这个方法在jsvm-api中已定义
    GetResultType(env, result);
    return result;
}
```

ArkTS侧示例代码

```ts
let script: string = `
  let arr = [10, 'hello', null, true];
  getElement(arr, 3)
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getElement: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getElement error: %{public}s', error.message);
}
```

### OH_JSVM_HasElement

若给定对象的指定索引处拥有属性，获取该元素。

cpp部分代码

```cpp
// HasElement注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasElement},
};
static JSVM_CallbackStruct *method = param;
// HasElement方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_HasElement的样例方法
static JSVM_Value HasElement(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取要判断的元素的索引
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // 判断指定索引位置的元素是否存在
    bool hasElement = true;
    OH_JSVM_HasElement(env, args[0], index, &hasElement);
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, hasElement, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
let script: string = `
  let arr = [10, 'hello', null, true];
`
let scriptTrue: string = script + `\n` + `
  hasElement(arr, 0)
`
let scriptFalse: string = script + `\n` + `
  hasElement(arr, 4)
`
try {
  let resultTrue = napitest.runJsVm(scriptTrue);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM hasElement 0: %{public}s', resultTrue);
  let resultFalse = napitest.runJsVm(scriptFalse);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM hasElement 4: %{public}s', resultFalse);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM hasElement error: %{public}s', error.message);
}
```

### OH_JSVM_DeleteElement

尝试删除给定对象的指定索引处的元素。

cpp部分代码

```cpp
// DeleteElement注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DeleteElement},
};
static JSVM_CallbackStruct *method = param;
// DeleteElement方法别名，供TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"deleteElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_DeleteElement的样例方法
static JSVM_Value DeleteElement(JSVM_Env env, JSVM_CallbackInfo info) {
    // 获取js侧传入的两个参数
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 获取要删除的元素的索引
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // 尝试删除请求索引位置的元素
    bool deleted = true;
    OH_JSVM_DeleteElement(env, args[0], index, &deleted);
    // 将bool结果转换为JSVM_Value并返回
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, deleted, &result);
    return result;
}
```

ArkTS侧示例代码

```ts
let script: string = `
  let arr = [10, 'hello', null, true];
  deleteElement(arr, 0)
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM deleteElement: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM deleteElement error: %{public}s', error.message);
}
```

### OH_JSVM_IsDataview

判断一个JavaScript对象是否为Dataview类型对象。

cpp部分代码

```cpp
// IsDataView注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDataView},
};
static JSVM_CallbackStruct *method = param;
// IsDataView方法别名，TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_IsDataview的样例方法
static JSVM_Value IsDataView(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 调用OH_JSVM_IsDataview接口判断给定入参是否为DataView数据。
    bool result = false;
    OH_JSVM_IsDataview(env, args[0], &result);
    JSVM_Value isDateView = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDateView);
    return isDateView;
}
```

ArkTS侧示例代码

```ts
let script: string = `
let buffer = new ArrayBuffer(16);
let dataView = new DataView(buffer);
isDataView(dataView);
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "IsDataView: %{public}s", result);
} catch (error) {
  hilog.error(0x0000, "JSVM", "IsDataView: %{public}s", error.message);
}
```

### OH_JSVM_IsTypedarray

判断一个JavaScript对象是否为Typedarray类型对象。

cpp部分代码

```cpp
// IsTypedarray注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsTypedarray},
};
static JSVM_CallbackStruct *method = param;
// IsTypedarray方法别名，TS侧调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isTypedarray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// OH_JSVM_IsTypedarray的样例方法
static JSVM_Value IsTypedarray(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    OH_JSVM_IsTypedarray(env, args[0], &result);
    JSVM_Value isTypedArray = nullptr;
    OH_JSVM_GetBoolean(env, result, &isTypedArray);
    return isTypedArray;
}
```

ArkTS侧示例代码

```ts
let script: string = `
         isTypedarray(new Uint16Array([1, 2, 3, 4]))
       `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, "JSVM", "IsTypedArray: %{public}s", result);
} catch (error) {
  hilog.error(0x0000, "JSVM", "IsTypedArray: %{public}s", error.message);
}
```
