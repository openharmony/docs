# Working with Arrays Using JSVM-API

## Introduction

JSVM-API provides APIs for directly managing JS arrays.

## Basic Concepts

JSVM-API can be used to create, access, modify, and traverse arrays. Before using JSVM-API, it's helpful if you understand the following concepts:

- Array creation: You can use **OH_JSVM_CreateArray** to create an array and pass it to the JS layer.
- Array-related operations: You can use the APIs provides by the JSVM module to obtain the length of a JS array, retrieve the element at the specified index, and set the element value at the specified index.
- **TypedArray**: A **TypedArray** object in JS is an array-like view of an underlying binary data buffer. It can be simply understood as an array of elements of the specified type. There is no constructor for **TypedArray** objects, but its child class constructor can be used to construct **TypedArray** data. The child classes of **TypedArray** include **Int8Array**, **Uint8Array**, **Uint8ClampedArray**, **Int16Array**, and **Int32Array**.
- **DataView**: **DataView** is a JS view that allows a variety of number types to be read and written in an **ArrayBuffer** object.
- **ArrayBuffer**: **ArrayBuffer** is a data struct used to represent a binary data buffer of fixed length.

## Available APIs

| API                        | Description                                  |
| ---------------------------- | ------------------------------------------ |
|OH_JSVM_CreateArray | Creates a JS array object.|
|OH_JSVM_CreateArrayWithLength | Creates a JS array object of the specified length.|
|OH_JSVM_CreateTypedarray | Creates a JS **TypedArray** object for an **ArrayBuffer**. The **TypedArray** object provides an array-like view over an underlying data buffer, where each element has the same underlying binary scalar data type.|
|OH_JSVM_CreateDataview | Creates a JS **DataView** object for an **ArrayBuffer**. The **DataView** object provides an array-like view of over an underlying data buffer.|
|OH_JSVM_GetArrayLength | Obtains the length of an array.|
|OH_JSVM_GetTypedarrayInfo | Obtains information about a **TypedArray** object.|
|OH_JSVM_GetDataviewInfo | Obtains information of a **DataView** object.|
|OH_JSVM_IsArray | Checks whether a JS object is an array.|
|OH_JSVM_SetElement | Sets an element at the specified index for a JS object.|
|OH_JSVM_GetElement | Obtains the element at the specified index of a JS object.|
|OH_JSVM_HasElement | Checks whether a JS object has an element at the specified index.|
|OH_JSVM_DeleteElement | Deletes the element at the specified index from a JS object.|
|OH_JSVM_IsDataview | Checks whether a JS object is a **DataView** object.|
|OH_JSVM_IsTypedarray | Checks whether a JS object is a **TypedArray** object.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code for array management. The **OH_JSVM_CreateTypedarray** API is different. For details, see the example.

### OH_JSVM_CreateArray

Creates a JS array object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateArray callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArray},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createArray and associate it with a callback. This allows the CreateArray callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static int DIFF_VALUE_FIVE = 5;
// Define OH_JSVM_CreateArray. 
static JSVM_Value CreateArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create an empty array.
    JSVM_Value array = nullptr;
    JSVM_Status status = OH_JSVM_CreateArray(env, &array);
    // Assign values to the created array.
    for (int i = 0; i < DIFF_VALUE_FIVE; i++) {
        JSVM_Value element;
        OH_JSVM_CreateInt32(env, i, &element);
        OH_JSVM_SetElement(env, array, i, element);
    }
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateArray success");
    }
    return array;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
  function testCreateArray() {
    return createArray();
  }
  testCreateArray()
`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateArray: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateArray error: %{public}s', error.message);
}
```

### OH_JSVM_CreateArrayWithLength

Creates a JS array object of the specified length.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateArrayWithLength callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArrayWithLength},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createArrayWithLength and associate it with a callback. This allows the CreateArrayWithLength callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArrayWithLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateArrayWithLength.
static JSVM_Value CreateArrayWithLength(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value result = nullptr;
    // Obtain the callback information.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Obtain the array length passed.
    int32_t length;
    OH_JSVM_GetValueInt32(env, argv[0], &length);
    // Call OH_JSVM_CreateArrayWithLength to create an array with the specified length.
    JSVM_Status status = OH_JSVM_CreateArrayWithLength(env, length, &result);
    if (status == JSVM_OK) {
        // Set an element in the created array.
        for (int32_t i = 0; i < length; i++) {
            JSVM_Value value;
            OH_JSVM_CreateInt32(env, i, &value);
            OH_JSVM_SetElement(env, result, i, value);
        }
        OH_LOG_INFO(LOG_APP, "JSVM CreateArrayWithLength success");
    } else {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArrayWithLength fail");
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let num = 7;
let script: string = `
  function testCreateArrayWithLength(num) {
    return createArrayWithLength(num);
  }
  testCreateArrayWithLength(${num})
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateArrayWithLength: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateArrayWithLength error: %{public}s', error.message);
}
```

### OH_JSVM_CreateTypedarray

Creates a JS **TypedArray** object for an **ArrayBuffer**. The **TypedArray** object provides an array-like view over an underlying data buffer, where each element has the same underlying binary scalar data type.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateTypedArray callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateTypedArray},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createTypedArray and associate it with a callback. This allows the CreateTypedArray callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createTypedArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateTypedarray.
static int DIFF_VALUE_THREE = 3;
static JSVM_Value CreateTypedArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int32_t typeNum;
    OH_JSVM_GetValueInt32(env, args[0], &typeNum);
    JSVM_TypedarrayType arrayType;
    // Set the element size.
    size_t elementSize = 0;
    // Convert the value to the JSVM_TypedarrayType type.
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
        // By default, an array of the JSVM_INT8_ARRAY type is created.
        arrayType = JSVM_INT8_ARRAY;
        elementSize = sizeof(int8_t);
        break;
    }
    size_t length = DIFF_VALUE_THREE;
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value typedArray = nullptr;
    void *data;
    // Create an ArrayBuffer object.
    OH_JSVM_CreateArraybuffer(env, length * elementSize, (void **)&data, &arrayBuffer);
    // Create a TypedArray object of the specified type.
    JSVM_Status status = OH_JSVM_CreateTypedarray(env, arrayType, length, arrayBuffer, 0, &typedArray);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateTypedArray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateTypedArray success");
    }
    return typedArray;
}
```

Modify the module initialization in **use-jsvm-process.md** as follows:

```cpp
// hello.cpp
static napi_value Init(napi_env env, napi_value exports) {
    // The defined TypedArray type is used by JS to store JSVM_TypedArrayType. For details, see createTypedArray sample code in ArkTS code. You can determine whether to use it based on service requirements.
    napi_value typedArrayTypes;
    napi_create_object(env, &typedArrayTypes);
    napi_value typeIndex;
    std::string typeKeys[] = {
        "INT8_ARRAY",   "UINT8_ARRAY",   "UINT8_CLAMPED_ARRAY", "INT_ARRAY",      "UINT16_ARRAY",    "INT32_ARRAY",
        "UINT32_ARRAY", "FLOAT32_ARRAY", "FLOAT64_ARRAY",       "BIGINT64_ARRAY", "BIGUINT64_ARRAY",
    };
    for (int32_t i = 0; i < sizeof(typeKeys) / sizeof(typeKeys[0]); i++) {
        napi_create_int32(env, i, &typeIndex);
        napi_set_named_property(env, typedArrayTypes, typeKeys[i].c_str(), typeIndex);
    }
    // Create the mappings between the ArkTS and C++ APIs.
    napi_property_descriptor desc[] = {
        {"runJsVm", nullptr, RunJsVm, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"TypedArrayTypes", nullptr, nullptr, nullptr, nullptr, typedArrayTypes, napi_default, nullptr},
    };
    // Register the native RunJsVm function with the JS exports object, making the native API available to JS.
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  // Pass in the TypedArray type to set, for example, INT8_ARRAY.
  let type: number = napitest.TypedArrayTypes["INT8_ARRAY"];
  let script: string = `
    createTypedArray(${type})
    `;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray error: %{public}s', error.message);
}
try {
  // Pass in the TypedArray type to set, for example, INT32_ARRAY.
  let type: number = napitest.TypedArrayTypes["INT32_ARRAY"];
  let str: string = `createTypedArray(${type})`;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateTypedArray error: %{public}s', error.message);
}
```

### OH_JSVM_CreateDataview

Creates a JS **DataView** object for an **ArrayBuffer**. The **DataView** object provides an array-like view of over an underlying data buffer.

CPP code:

```cpp
// Register the CreateDataView callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDataView},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDataView and associate it with a callback. This allows the CreateDataView callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
static int DIFF_VALUE_FOUR = 4;
static int DIFF_VALUE_TWELVE = 12;
// Define OH_JSVM_CreateDataview.
static JSVM_Value CreateDataView(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value result = nullptr;
    // Byte length of DataView.
    size_t byteLength = DIFF_VALUE_TWELVE;
    // Offset of the byte.
    size_t byteOffset = DIFF_VALUE_FOUR;
    // Obtain the parameters of the callback.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into the object type.
    OH_JSVM_CoerceToObject(env, args[0], &arrayBuffer);
    // Create a DataView object with the specified byte length and offset.
    JSVM_Status status = OH_JSVM_CreateDataview(env, byteLength, arrayBuffer, byteOffset, &result);
    // Obtain the pointer to the DataView object and the length.
    uint8_t *data = nullptr;
    size_t length = 0;
    // Assign values to DataView.
    for (size_t i = 0; i < length; i++) {
        data[i] = static_cast<uint8_t>(i + 1);
    }
    int32_t infoType;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);
    size_t returnLength;
    JSVM_Value returnArrayBuffer = nullptr;
    size_t returnOffset;
    enum InfoType { BYTE_LENGTHE, ARRAY_BUFFERE, BYTE_OFFSET };
    // Obtain DataView information.
    OH_JSVM_GetDataviewInfo(env, result, &returnLength, (void **)&data, &returnArrayBuffer, &returnOffset);
    JSVM_Value returnResult = nullptr;
    switch (infoType) {
    case BYTE_LENGTHE:
        JSVM_Value len;
        OH_JSVM_CreateInt32(env, returnLength, &len);
        returnResult = len;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success returnLength:%{public}d", returnLength);
        }
        break;
    case ARRAY_BUFFERE:
        bool isArraybuffer;
        OH_JSVM_IsArraybuffer(env, returnArrayBuffer, &isArraybuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArraybuffer, &isArray);
        returnResult = isArray;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success isArraybuffer:%{public}d", isArraybuffer);
        }
        break;
    case BYTE_OFFSET:
        JSVM_Value offset;
        OH_JSVM_CreateInt32(env, returnOffset, &offset);
        returnResult = offset;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success returnOffset:%{public}d", returnOffset);
        }
        break;
    default:
        break;
    }
    return returnResult;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let BYTE_LENGTGH = 0;
  let str: string = `
  createDataView(new ArrayBuffer(16), ${BYTE_LENGTGH})
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createDataView len: %{public}s', result);
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
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createDataView offset: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createDataView error: %{public}s', error.message);
}
```

### OH_JSVM_GetArrayLength

Obtains the length of an array.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetArrayLength callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetArrayLength},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getArrayLength and associate it with a callback. This allows the GetArrayLength callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getArrayLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetArrayLength.
static JSVM_Value GetArrayLength(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_Value result = nullptr;
    uint32_t length;
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Check whether the parameter is an array.
    bool isArray = false;
    OH_JSVM_IsArray(env, args[0], &isArray);
    if (!isArray) {
        OH_LOG_INFO(LOG_APP, "JSVM Argument must be an array");
        return nullptr;
    }
    OH_JSVM_GetArrayLength(env, args[0], &length);
    // Create a return value.
    OH_JSVM_CreateInt32(env, length, &result);
    OH_LOG_INFO(LOG_APP, "JSVM length: %{public}d", length);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let data =  '[0, 1, 2, 3, 4, 5]';
let str: string = `
  getArrayLength(${data})
  `;
try {
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetArrayLength: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetArrayLength error: %{public}s', error.message);
}
```

### OH_JSVM_GetTypedarrayInfo

Obtains information about a **TypedArray** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetTypedArrayInfo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetTypedArrayInfo},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getTypedArrayInfo and associate it with a callback. This allows the GetTypedArrayInfo callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getTypedArrayInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetTypedarrayInfo.
static JSVM_Value GetTypedArrayInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse the parameters passed to a JS callback within a JSVM. The first parameter is the TypedArray type of the information to obtain, and the second parameter is the enums of the information type to obtain.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    // Convert the second parameter to the int32 type for comparison.
    int32_t infoTypeParam;
    OH_JSVM_GetValueInt32(env, args[1], &infoTypeParam);
    // Define the infoType enums in the same sequence as those in ArkTS.
    enum InfoType { INFO_TYPE, INFO_LENGTH, INFO_ARRAY_BUFFER, INFO_BYTE_OFFSET };
    void *data;
    JSVM_TypedarrayType type;
    size_t byteOffset, length;
    JSVM_Value arrayBuffer = nullptr;
    // Call OH_JSVM_GetTypedarrayInfo to obtain TypedArray information.
    JSVM_Status status = OH_JSVM_GetTypedarrayInfo(env, args[0], &type, &length, &data, &arrayBuffer, &byteOffset);
    JSVM_Value result = nullptr;
    // Return the property value based on the property name.
    switch (infoTypeParam) {
    case INFO_TYPE:
        // If the input parameter is TypedArray data of the int8 type, the value type is JSVM_INT8_ARRAY.
        JSVM_Value int8_type;
        OH_JSVM_GetBoolean(env, type == JSVM_INT8_ARRAY, &int8_type);
        result = int8_type;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success is JSVM_INT8_ARRAY:%{public}d", type == JSVM_INT8_ARRAY);
        }
        break;
    case INFO_LENGTH:
        // Number of elements in the TypedArray object.
        JSVM_Value jsvmLength;
        OH_JSVM_CreateInt32(env, length, &jsvmLength);
        result = jsvmLength;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success length:%{public}d", length);
        }
        break;
    case INFO_BYTE_OFFSET:
        // Byte offset of the first TypedArray element in the native array.
        JSVM_Value jsvmOffset;
        OH_JSVM_CreateInt32(env, byteOffset, &jsvmOffset);
        result = jsvmOffset;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success byteOffset:%{public}d", byteOffset);
        }
        break;
    case INFO_ARRAY_BUFFER:
        // ArrayBuffer under TypedArray.
        bool isArrayBuffer;
        OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
        result = isArray;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success isArrayBuffer:%{public}d", isArrayBuffer);
        }
        break;
    default:
        break;
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  // is JSVM_INT8_ARRAY
  let str: string = `
  getTypedArrayInfo(new Int8Array(3), 0)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // Length
  let str: string = `
  getTypedArrayInfo(new Int8Array(5), 1)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // is_arraybuffer
  let str: string = `
  getTypedArrayInfo(new Int8Array(5), 2)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
try {
  // Byte offset.
  let str: string = `
  getTypedArrayInfo(new Int8Array(1), 3)
  `;
  let result = napitest.runJsVm(str);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetTypedArrayInfo error: %{public}s', error.message);
}
```

### OH_JSVM_GetDataviewInfo

Obtains information of a **DataView** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetDataViewInfo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDataViewInfo},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getDataViewInfo and associate it with a callback. This allows the GetDataViewInfo callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDataViewInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetDataviewInfo.
static JSVM_Value GetDataViewInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse the parameters passed to a JS callback within a JSVM. The first parameter is the DataView type of the information to obtain, and the second parameter is the enums of the information type to obtain.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the second parameter to an int32 number.
    int32_t infoType;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);
    size_t byteLength;
    void *data;
    JSVM_Value arrayBuffer = nullptr;
    size_t byteOffset;
    // Define the infoType enums in the same sequence as those in ArkTS.
    enum infoTypeEnum { BYTE_LENGTHE, ARRAY_BUFFERE, BYTE_OFFSET };
    // Obtain DataView information.
    JSVM_Status status = OH_JSVM_GetDataviewInfo(env, args[0], &byteLength, &data, &arrayBuffer, &byteOffset);
    JSVM_Value result = nullptr;
    switch (infoType) {
    case BYTE_LENGTHE:
        // Return the length of DataView.
        JSVM_Value len;
        OH_JSVM_CreateInt32(env, byteLength, &len);
        result = len;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success byteLength:%{public}d", byteLength);
        }
        break;
    case ARRAY_BUFFERE:
        // Check whether data in Info of DataView is an ArrayBuffer object.
        bool isArrayBuffer;
        OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer);
        JSVM_Value isArray;
        OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
        result = isArray;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success isArrayBuffer:%{public}d", isArrayBuffer);
        }
        break;
    case BYTE_OFFSET:
        // Return the offset of DataView.
        JSVM_Value offset;
        OH_JSVM_CreateInt32(env, byteOffset, &offset);
        result = offset;
        if (status != JSVM_OK) {
            OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
        } else {
            OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success byteOffset:%{public}d", byteOffset);
        }
        break;
    default:
        break;
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  // Byte length.
  let script: string = `getDataViewInfo(new DataView(new Int8Array([2,5]).buffer), 0)`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // Check whether the data is an ArrayBuffer object.
  let data = `'a'`;
  let isarraybuffer = '1';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // Check whether the data is an ArrayBuffer object.
  let data = 'new DataView(new Int8Array([2,5,3]).buffer)';
  let isarraybuffer = '1';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
try {
  // byte_offset
  let data = 'new DataView(new Int8Array([2,5,3]).buffer)';
  let isarraybuffer = '2';
  let script: string = `getDataViewInfo(${data}, ${isarraybuffer})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM getDataViewInfo error: %{public}s', error.message);
}
```

### OH_JSVM_IsArray

Checks whether a JS object is an array.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsArray callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsArray},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isArray and associate it with a callback. This allows the IsArray callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_IsArray.
static JSVM_Value IsArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_IsArray(env, args[0], &result);
    JSVM_Value returnValue = nullptr;
    OH_JSVM_GetBoolean(env, result, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsArray success:%{public}d", result);
    }
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let data = '[1, 2, 3, 4, 5]';
let script: string = `
   isArray(${data})
 `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'IsArray: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'IsArray: %{public}s', error.message);
}
```

### OH_JSVM_SetElement

Sets an element at the specified index for a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the SetElement callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetElement},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named setElement and associate it with a callback. This allows the SetElement callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"setElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_SetElement.
static int DIFF_VALUE_THREE = 3;
static JSVM_Value SetElement(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = DIFF_VALUE_THREE;
    JSVM_Value args[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int32_t index = 0;
    OH_JSVM_GetValueInt32(env, args[1], &index);
    JSVM_Status status = OH_JSVM_SetElement(env, args[0], index, args[2]);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM SetElement fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM SetElement success");
    }
    return args[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
  setElement(3)
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM setElement: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM setElement error: %{public}s', error.message);
}
```

### OH_JSVM_GetElement

Obtains the element at the specified index of a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetElement callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetElement},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getElement and associate it with a callback. This allows the GetElement callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetElement.
static JSVM_Value GetElement(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index value of the element.
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // Obtain the element value at the index and store it in result.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetElement(env, args[0], index, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetElement fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetElement success");
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
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

Checks whether a JS object has an element at the specified index.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the HasElement callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasElement},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named hasElement and associate it with a callback. This allows the HasElement callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_HasElement.
static JSVM_Value HasElement(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index of the element to be checked.
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // Check whether the element exists based on the given index.
    bool hasElement = true;
    JSVM_Status status = OH_JSVM_HasElement(env, args[0], index, &hasElement);
    // Convert the boolean value to JSVM_Value and return it.
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, hasElement, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM hasElement fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JSVM hasElement: %{public}d", hasElement);
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
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
  hilog.info(0x0000, 'testJSVM', 'Test JSVM resultTrue: %{public}s', resultTrue);
  let resultFalse = napitest.runJsVm(scriptFalse);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM resultFalse: %{public}s', resultFalse);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM hasElement error: %{public}s', error.message);
}
```

### OH_JSVM_DeleteElement

Deletes the element at the specified index from a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the DeleteElement callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DeleteElement},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named deleteElement and associate it with a callback. This allows the DeleteElement callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"deleteElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_DeleteElement.
static JSVM_Value DeleteElement(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the two parameters passed from JS.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index of the element to delete.
    uint32_t index;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // Delete the element at the specified index.
    bool deleted = true;
    JSVM_Status status = OH_JSVM_DeleteElement(env, args[0], index, &deleted);
    // Convert the boolean value to JSVM_Value and return it.
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, deleted, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM DeleteElement fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JSVM DeleteElement: %{public}d", deleted);
    }
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
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

Checks whether a JS object is a **DataView** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsDataView callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDataView},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isDataView and associate it with a callback. This allows the IsDataView callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_IsDataview.
static JSVM_Value IsDataView(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_IsDataview to check whether the input parameter is a DataView object.
    bool result = false;
    JSVM_Status status = OH_JSVM_IsDataview(env, args[0], &result);
    JSVM_Value isDateView = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDateView);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDataView fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JSVM IsDataView: %{public}d", result);
    }
    return isDateView;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
let buffer = new ArrayBuffer(16);
let dataView = new DataView(buffer);
isDataView(dataView);
  `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'IsDataView: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'IsDataView: %{public}s', error.message);
}
```

### OH_JSVM_IsTypedarray

Checks whether a JS object is a **TypedArray** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsTypedarray callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsTypedarray},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isTypedarray and associate it with a callback. This allows the IsTypedarray callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isTypedarray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_IsTypedarray.
static JSVM_Value IsTypedarray(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_IsTypedarray(env, args[0], &result);
    JSVM_Value isTypedArray = nullptr;
    OH_JSVM_GetBoolean(env, result, &isTypedArray);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsTypedarray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM JSVM IsTypedarray: %{public}d", result);
    }
    return isTypedArray;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
         isTypedarray(new Uint16Array([1, 2, 3, 4]))
       `
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'IsTypedArray: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'IsTypedArray: %{public}s', error.message);
}
```
