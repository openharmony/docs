# Working with Arrays Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=2b8002975a0c421d94edbe70b3817da05adefb9a translatedAt=2026-08-12T06:31:13.295Z pushedAt=2026-08-12T10:52:21.336Z -->

## Introduction

JSVM-API provides APIs for directly managing JavaScript (JS) arrays.

## Basic Concepts

JSVM-API can be used to create, access, modify, and traverse arrays. Before using JSVM-API to work with arrays, it is helpful if you understand the following concepts:

- **Array creation**: If you need to create a new JavaScript array in a JSVM module, you can use the `OH_JSVM_CreateArray` API to create the array and pass it to the JavaScript layer.

- Array-related operations: You can use the APIs provided by the JSVM module to obtain the length of a JS array, retrieve the element at the specified index, and set the element value of the specified index.

- **TypedArray**: A **TypedArray** object in JS is an array-like view of an underlying binary data buffer. It can be regarded as an array-like data view of the specified type. There is no constructor for **TypedArray** objects, but they can be constructed by their child class constructors. The child classes of **TypedArray** include **Int8Array**, **Uint8Array**, **Uint8ClampedArray**, **Int16Array**, and **Int32Array**.

- **ArrayBuffer**: **ArrayBuffer** is a data struct used to represent a binary data buffer of fixed length.

- **DataView**: **DataView** is a JS view that allows a variety of number types to be read and written in an **ArrayBuffer** object.

## Available APIs

| API                        | Description                                  |
| ---------------------------- | ------------------------------------------ |
|OH_JSVM_CreateArray | Creates a JS array object.|
|OH_JSVM_CreateArrayWithLength | Creates a JS array object of the specified length.|
|OH_JSVM_CreateTypedarray | Creates a JS **TypedArray** object for an **ArrayBuffer**. The TypedArray object provides an array-like view, where each element has the same binary scalar data type. Note that the sum of **length** × **size_of_element** and **byte_offset** must be less than or equal to the array size (in bytes). Otherwise, a **RangeError** exception will be thrown.|
|OH_JSVM_CreateDataview | Creates a JS **DataView** object based on an existing **ArrayBuffer**. The **DataView** object provides an array-like view on the underlying data buffer. The **ArrayBuffer** allows elements of different sizes and types. <br>The sum of **byte_length** and **byte_offset** must be less than or equal to the array size (in bytes). Otherwise, a **RangeError** exception will be thrown.|
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

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in array development.

### OH_JSVM_CreateArray

Use **OH_JSVM_CreateArray** to create a JS array object.

CPP code:

<!-- @[oh_jsvm_create_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/createarray/src/main/cpp/hello.cpp) -->  

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"

// ...

static int g_diffValueFive = 5;
// Sample method for OH_JSVM_CreateArray
static JSVM_Value CreateArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Create an empty array.
    JSVM_Value array = nullptr;
    JSVM_Status status = OH_JSVM_CreateArray(env, &array);
    // Assign values to the created array.
    for (int i = 0; i < g_diffValueFive; i++) {
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
// CreateArray register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArray},
};
static JSVM_CallbackStruct *method = param;
// CreateArray method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
  function testCreateArray() {
    return createArray();
  }
  testCreateArray();
)JS";
```

Expected result:

```txt
JSVM CreateArray success
```

### OH_JSVM_CreateArrayWithLength

Use **OH_JSVM_CreateArrayWithLength** to create a JS array object of the specified length.

CPP code:

<!-- @[oh_jsvm_create_array_with_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/createarraywithlength/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateArrayWithLength
static JSVM_Value CreateArrayWithLength(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value result = nullptr;
    // Parse the passed parameters with OH_JSVM_GetCbInfo.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    // Obtain the passed array length.
    int32_t length = 0;
    OH_JSVM_GetValueInt32(env, argv[0], &length);
    // Create an array of the passed fixed length using OH_JSVM_CreateArrayWithLength.
    JSVM_Status status = OH_JSVM_CreateArrayWithLength(env, length, &result);
    if (status == JSVM_OK) {
        // Set values for the created array.
        for (int32_t i = 0; i < length; i++) {
            JSVM_Value value;
            JSVM_CALL(OH_JSVM_CreateInt32(env, i, &value));
            JSVM_CALL(OH_JSVM_SetElement(env, result, i, value));
        }
        OH_LOG_INFO(LOG_APP, "JSVM CreateArrayWithLength success");
    } else {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArrayWithLength fail");
    }
    return result;
}
// CreateArrayWithLength register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArrayWithLength},
};
static JSVM_CallbackStruct *method = param;
// CreateArrayWithLength method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArrayWithLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
let num = 7;
function testCreateArrayWithLength(num) {
    return createArrayWithLength(num);
}
testCreateArrayWithLength(num);
)JS";
```

Expected result:

```txt
JSVM CreateArrayWithLength success
```

### OH_JSVM_CreateTypedarray

Creates a JavaScript TypedArray object on an existing ArrayBuffer. The TypedArray object provides an array-like view over the underlying data buffer, where each element has the same underlying binary scalar data type.

CPP code:

<!-- @[oh_jsvm_create_typedarray](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/createtypedarray/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_CreateTypedarray
static int g_diffValueThree = 3;
static JSVM_Value CreateTypedArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    int32_t typeNum = 0;
    OH_JSVM_GetValueInt32(env, args[0], &typeNum);
    JSVM_TypedarrayType arrayType;
    // Used to store the size of each element.
    size_t elementSize = 0;
    // Convert to the JSVM_TypedarrayType type.
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
            // Create the JSVM_INT8_ARRAY type by default.
            arrayType = JSVM_INT8_ARRAY;
            elementSize = sizeof(int8_t);
            break;
    }
    size_t length = g_diffValueThree;
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value typedArray = nullptr;
    void *data;
    // Create an ArrayBuffer.
    OH_JSVM_CreateArraybuffer(env, length * elementSize, (void **)&data, &arrayBuffer);
    // Create a TypedArray based on the given type.
    JSVM_Status status = OH_JSVM_CreateTypedarray(env, arrayType, length, arrayBuffer, 0, &typedArray);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateTypedArray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateTypedArray success");
    }
    return typedArray;
}
// CreateTypedArray register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateTypedArray},
};
static JSVM_CallbackStruct *method = param;
// CreateTypedArray method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"createTypedArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
const type = {
    INT8_ARRAY: 0,
    UINT8_ARRAY: 1,
    UINT8_CLAMPED_ARRAY: 2,
    INT16_ARRAY: 3,
    UINT16_ARRAY: 4,
    INT32_ARRAY: 5,
    UINT32_ARRAY: 6,
    FLOAT32_ARRAY: 7,
    FLOAT64_ARRAY: 8,
    BIGINT64_ARRAY: 9,
    BIGUINT64_ARRAY: 10
};
createTypedArray(type.INT8_ARRAY);
createTypedArray(type.INT32_ARRAY);
)JS";
```

Expected result:

```txt
JSVM CreateTypedArray success
JSVM CreateTypedArray success
```

### OH_JSVM_CreateDataview

Use **OH_JSVM_CreateDataview** to create a JS **DataView** object based on an **ArrayBuffer**. The **DataView** object provides an array-like view over an underlying data buffer.

CPP code:

<!-- @[oh_jsvm_create_dataview](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/createdataview/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

static int g_diffValueFour = 4;
static int g_diffValueTwelve = 12;

// Sample method for OH_JSVM_CreateDataview
static JSVM_Value CreateDataView(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from the JS side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_Value arrayBuffer = nullptr;
    JSVM_Value result = nullptr;
    // Byte length of the DataView.
    size_t byteLength = g_diffValueFour;
    // Byte offset.
    size_t byteOffset = g_diffValueTwelve;
    // Obtain the parameter information of the callback function.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter to the object type.
    OH_JSVM_CoerceToObject(env, args[0], &arrayBuffer);
    // Create a DataView object with the specified byte length and byte offset.
    JSVM_Status status = OH_JSVM_CreateDataview(env, byteLength, arrayBuffer, byteOffset, &result);
    // Obtain the pointer and length information of the DataView.
    uint8_t *data = nullptr;
    size_t length = 0;
    // Assign values to the DataView.
    for (size_t i = 0; i < length; i++) {
        data[i] = static_cast<uint8_t>(i + 1);
    }
    int32_t infoType = 0;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);
    size_t returnLength = 0;
    JSVM_Value returnArrayBuffer = nullptr;
    size_t returnOffset = 0;
    enum InfoType { BYTE_LENGTH, ARRAY_BUFFER, BYTE_OFFSET };
    // Obtain DataView information.
    OH_JSVM_GetDataviewInfo(env, result, &returnLength, (void **)&data, &returnArrayBuffer, &returnOffset);
    JSVM_Value returnResult = nullptr;
    switch (infoType) {
        case BYTE_LENGTH:
            JSVM_Value len = nullptr;
            JSVM_CALL(OH_JSVM_CreateInt32(env, returnLength, &len));
            returnResult = len;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success, returnLength: %{public}d", returnLength);
            }
            break;
        case ARRAY_BUFFER:
            bool isArraybuffer = false;
            JSVM_CALL(OH_JSVM_IsArraybuffer(env, returnArrayBuffer, &isArraybuffer));
            JSVM_Value isArray = nullptr;
            JSVM_CALL(OH_JSVM_GetBoolean(env, isArraybuffer, &isArray));
            returnResult = isArray;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success, isArraybuffer: %{public}d", isArraybuffer);
            }
            break;
        case BYTE_OFFSET:
            JSVM_Value offset = nullptr;
            JSVM_CALL(OH_JSVM_CreateInt32(env, returnOffset, &offset));
            returnResult = offset;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM CreateDataView fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM CreateDataView success, returnOffset: %{public}d", returnOffset);
            }
            break;
        default:
            break;
    }
    return returnResult;
}
// CreateDataView register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDataView},
};
static JSVM_CallbackStruct *method = param;
// CreateDataView method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
 let BYTE_LENGTH = 0;
 createDataView(new ArrayBuffer(16), BYTE_LENGTH);
 let IS_ARRAYBUFFER = 1;
 createDataView(new ArrayBuffer(16), IS_ARRAYBUFFER);
 let BYTE_OFFSET = 2;
 createDataView(new ArrayBuffer(16), BYTE_OFFSET);
)JS";
```

Expected result:

```txt
JSVM CreateDataView success, returnLength: 12
JSVM CreateDataView success, isArraybuffer: 1
JSVM CreateDataView success, returnOffset: 4
```

### OH_JSVM_GetArrayLength

Use **OH_JSVM_GetArrayLength** to obtain the length of an array.

CPP code:

<!-- @[oh_jsvm_get_array_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/getarraylength/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetArrayLength
static JSVM_Value GetArrayLength(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_Value result = nullptr;
    uint32_t length = 0;
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Check whether the parameter is an array.
    bool isArray = false;
    OH_JSVM_IsArray(env, args[0], &isArray);
    if (!isArray) {
        OH_LOG_INFO(LOG_APP, "JSVM Argument must be an array");
        return nullptr;
    }
    JSVM_Status status = OH_JSVM_GetArrayLength(env, args[0], &length);
    if (status == JSVM_OK) {
        // Create the return value.
        JSVM_CALL(OH_JSVM_CreateInt32(env, length, &result));
        OH_LOG_INFO(LOG_APP, "JSVM length: %{public}d", length);
    }
    return result;
}
// GetArrayLength register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetArrayLength},
};
static JSVM_CallbackStruct *method = param;
// GetArrayLength method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"getArrayLength", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
let data = [0, 1, 2, 3, 4, 5];
getArrayLength(data);
)JS";
```

Expected result:

```txt
JSVM length: 6
```

### OH_JSVM_GetTypedarrayInfo

Use **OH_JSVM_GetTypedarrayInfo** to obtain information about a **TypedArray** object.

CPP code:

<!-- @[oh_jsvm_get_typedarray_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/gettypedarrayinfo/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetTypedarrayInfo
static JSVM_Value GetTypedArrayInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse the parameters. The first parameter is the TypedArray data whose information is to be obtained, and the second parameter is the enumeration value of the information type to be obtained.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    // Convert the second parameter to the int32 type for comparison.
    int32_t infoTypeParam = 0;
    OH_JSVM_GetValueInt32(env, args[1], &infoTypeParam);
    // Define an enumeration type whose order and meaning are consistent with the infoType enumeration type on the ArkTS side.
    enum InfoType { INFO_TYPE, INFO_LENGTH, INFO_ARRAY_BUFFER, INFO_BYTE_OFFSET };
    void *data;
    JSVM_TypedarrayType type;
    size_t byteOffset = 0;
    size_t length = 0;
    JSVM_Value arrayBuffer = nullptr;
    // Call OH_JSVM_GetTypedarrayInfo to obtain information about the TypedArray data.
    JSVM_Status status = OH_JSVM_GetTypedarrayInfo(env, args[0], &type, &length, &data, &arrayBuffer, &byteOffset);
    JSVM_Value result = nullptr;
    // Return the corresponding property value of the TypedArray based on the property name.
    switch (infoTypeParam) {
        case INFO_TYPE:
            // If the passed parameter is int8 TypedArray data, its type is JSVM_INT8_ARRAY.
            JSVM_Value int8_type;
            OH_JSVM_GetBoolean(env, type == JSVM_INT8_ARRAY, &int8_type);
            result = int8_type;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
            } else {
                OH_LOG_INFO(
                    LOG_APP, "JSVM GetTypedArrayInfo success, JSVM_INT8_ARRAY: %{public}d", type == JSVM_INT8_ARRAY);
            }
            break;
        case INFO_LENGTH:
            // Number of elements in the TypedArray.
            JSVM_Value jsvmLength;
            JSVM_CALL(OH_JSVM_CreateInt32(env, length, &jsvmLength));
            result = jsvmLength;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success, length: %{public}d", length);
            }
            break;
        case INFO_BYTE_OFFSET:
            // Byte offset of the first element of the TypedArray in the underlying native array.
            JSVM_Value jsvmOffset;
            JSVM_CALL(OH_JSVM_CreateInt32(env, byteOffset, &jsvmOffset));
            result = jsvmOffset;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success, byteOffset: %{public}d", byteOffset);
            }
            break;
        case INFO_ARRAY_BUFFER:
            // ArrayBuffer underlying the TypedArray.
            bool isArrayBuffer = false;
            JSVM_CALL(OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer));
            JSVM_Value isArray = nullptr;
            OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
            result = isArray;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetTypedArrayInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetTypedArrayInfo success, isArrayBuffer: %{public}d", isArrayBuffer);
            }
            break;
        default:
            break;
    }
    return result;
}
// GetTypedArrayInfo register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetTypedArrayInfo},
};
static JSVM_CallbackStruct *method = param;
// GetTypedArrayInfo method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"getTypedArrayInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
// is JSVM_INT8_ARRAY
getTypedArrayInfo(new Int8Array(3), 0);
// length
getTypedArrayInfo(new Int8Array(5), 1);
// is_arraybuffer
getTypedArrayInfo(new Int8Array(5), 2);
// byteoffset
getTypedArrayInfo(new Int8Array(1), 3);
)JS";
```

Expected result:

```txt
JSVM GetTypedArrayInfo success, JSVM_INT8_ARRAY: 1
JSVM GetTypedArrayInfo success, length: 5
JSVM GetTypedArrayInfo success, isArrayBuffer: 1
JSVM GetTypedArrayInfo success, byteOffset: 0
```

### OH_JSVM_GetDataviewInfo

Obtains information about a DataView object.

CPP code:

<!-- @[oh_jsvm_get_dataview_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/getdataviewinfo/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetDataviewInfo
static JSVM_Value GetDataViewInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse the parameters. The first parameter is the DataView data whose information is to be obtained, and the second parameter is the enumeration value of the information type to be obtained.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the second parameter to an int32 number.
    int32_t infoType = 0;
    OH_JSVM_GetValueInt32(env, args[1], &infoType);
    size_t byteLength = 0;
    void *data;
    JSVM_Value arrayBuffer = nullptr;
    size_t byteOffset = 0;
    // Define an enumeration type whose order and meaning are consistent with the infoType enumeration type on the ArkTS side.
    enum InfoTypeEnum { BYTE_LENGTH, ARRAY_BUFFER, BYTE_OFFSET };
    // Obtain DataView information.
    JSVM_Status status = OH_JSVM_GetDataviewInfo(env, args[0], &byteLength, &data, &arrayBuffer, &byteOffset);
    JSVM_Value result = nullptr;
    switch (infoType) {
        case BYTE_LENGTH:
            // Return the queried DataView length.
            JSVM_Value len;
            JSVM_CALL(OH_JSVM_CreateInt32(env, byteLength, &len));
            result = len;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success, byteLength: %{public}d", byteLength);
            }
            break;
        case ARRAY_BUFFER:
            // Check whether the arraybuffer in the DataView info is an ArrayBuffer.
            bool isArrayBuffer = false;
            JSVM_CALL(OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer));
            JSVM_Value isArray = nullptr;
            OH_JSVM_GetBoolean(env, isArrayBuffer, &isArray);
            result = isArray;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success, isArrayBuffer: %{public}d", isArrayBuffer);
            }
            break;
        case BYTE_OFFSET:
            // Return the queried DataView offset.
            JSVM_Value offset;
            JSVM_CALL(OH_JSVM_CreateInt32(env, byteOffset, &offset));
            result = offset;
            if (status != JSVM_OK) {
                OH_LOG_ERROR(LOG_APP, "JSVM GetDataViewInfo fail");
            } else {
                OH_LOG_INFO(LOG_APP, "JSVM GetDataViewInfo success, byteOffset: %{public}d", byteOffset);
            }
            break;
        default:
            break;
    }
    return result;
}
// GetDataViewInfo register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDataViewInfo},
};
static JSVM_CallbackStruct *method = param;
// GetDataViewInfo method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDataViewInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
// bytelength
getDataViewInfo(new DataView(new Int8Array([2, 5]).buffer), 0);
// is arraybuffer
let data = 'a';
let isarraybuffer = 1;
getDataViewInfo(data, isarraybuffer);
// is arraybuffer
data = new DataView(new Int8Array([2, 5, 3]).buffer);
isarraybuffer = 1;
getDataViewInfo(data, isarraybuffer);
// byte_offset
data = new DataView(new Int8Array([2, 5, 3]).buffer);
isarraybuffer = 2;
getDataViewInfo(data, isarraybuffer);
)JS";
```

Expected result:

```txt
JSVM GetDataViewInfo success, byteLength: 2
JSVM GetDataViewInfo fail
JSVM GetDataViewInfo success, isArrayBuffer: 1
JSVM GetDataViewInfo success, byteOffset: 0
```

### OH_JSVM_IsArray

Use **OH_JSVM_IsArray** to check whether a JS object is an array.

CPP code:

<!-- @[oh_jsvm_is_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/isarray/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_IsArray
static JSVM_Value IsArray(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result = false;
    JSVM_Status status = OH_JSVM_IsArray(env, args[0], &result);
    JSVM_Value returnValue = nullptr;
    JSVM_CALL(OH_JSVM_GetBoolean(env, result, &returnValue));
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArray fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsArray success, IsArray: %{public}d", result);
    }
    return returnValue;
}
// IsArray register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsArray},
};
static JSVM_CallbackStruct *method = param;
// IsArray method alias for TS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"isArray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *srcCallNative = R"JS(
let data = [1, 2, 3, 4, 5];
isArray(data);
)JS";
```

Expected result:

```txt
JSVM IsArray success, IsArray: 1
```

### OH_JSVM_SetElement

Use **OH_JSVM_SetElement** to set an element at the specified index for a JS object.

CPP code:

<!-- @[oh_jsvm_set_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/setelement/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_SetElement
static int g_diffValueThree = 3;
static JSVM_Value SetElement(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = g_diffValueThree;
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
// SetElement register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = SetElement},
};
static JSVM_CallbackStruct *method = param;
// SetElement method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"setElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
setElement(3);
)JS";
```

Expected result:

```txt
JSVM SetElement success
```

### OH_JSVM_GetElement

Use **OH_JSVM_GetElement** to obtain the element at the specified index of a JS object.

CPP code:

<!-- @[oh_jsvm_get_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/getelement/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_GetElement
static JSVM_Value GetElement(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from the JS side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index value of the requested element.
    uint32_t index = 0;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // Obtain the element value at the requested index and store it in result.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_GetElement(env, args[0], index, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetElement fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetElement success");
    }
    return result;
}
// GetElement register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetElement},
};
static JSVM_CallbackStruct *method = param;
// GetElement method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"getElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
let arr = [10, 'hello', null, true];
getElement(arr, 3);
)JS";
```

Expected result:

```txt
JSVM GetElement success
```

### OH_JSVM_HasElement

Use **OH_JSVM_HasElement** to check whether a JS object has an element at the specified index.

C++ code:

<!-- @[oh_jsvm_has_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/haselement/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...

// Sample method for OH_JSVM_HasElement
static JSVM_Value HasElement(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from the JS side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index of the element to check.
    uint32_t index = 0;
    OH_JSVM_GetValueUint32(env, args[1], &index);
    // Check whether the element at the specified index exists.
    bool hasElement = true;
    JSVM_Status status = OH_JSVM_HasElement(env, args[0], index, &hasElement);
    // Convert the boolean result to JSVM_Value and return it.
    JSVM_Value result = nullptr;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM hasElement fail");
    } else {
        OH_JSVM_GetBoolean(env, hasElement, &result);
        OH_LOG_INFO(LOG_APP, "JSVM hasElement: %{public}d", hasElement);
    }
    return result;
}
// HasElement register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = HasElement},
};
static JSVM_CallbackStruct *method = param;
// HasElement method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"hasElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *srcCallNative = R"JS(
let arr = [10, 'hello', null, true];
hasElement(arr, 0);
hasElement(arr, 4);
)JS";
```

Expected result:

```txt
JSVM hasElement: 1
JSVM hasElement: 0
```

### OH_JSVM_DeleteElement

Use **OH_JSVM_DeleteElement** to delete the element at the specified index from a JS object.

CPP code:

<!-- @[oh_jsvm_delete_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/deleteelement/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_DeleteElement
static JSVM_Value DeleteElement(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the two parameters passed from the JS side.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // Obtain the index of the element to delete.
    uint32_t index = 0;
    JSVM_CALL(OH_JSVM_GetValueUint32(env, args[1], &index));
    // Attempt to delete the element at the requested index.
    bool deleted = true;
    JSVM_Status status = OH_JSVM_DeleteElement(env, args[0], index, &deleted);
    // Convert the boolean result to JSVM_Value and return it.
    JSVM_Value result = nullptr;
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM DeleteElement fail");
    } else {
        OH_JSVM_GetBoolean(env, deleted, &result);
        OH_LOG_INFO(LOG_APP, "JSVM DeleteElement: %{public}d", deleted);
    }
    return result;
}
// DeleteElement register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DeleteElement},
};
static JSVM_CallbackStruct *method = param;
// DeleteElement method alias for JS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"deleteElement", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *SRC_CALL_NATIVE = R"JS(
let arr = [10, 'hello', null, true];
deleteElement(arr, 0);
)JS";
```

Expected result:

```txt
JSVM DeleteElement: 1
```

### OH_JSVM_IsDataview

Determines whether a JavaScript object is a DataView object.

CPP code:

<!-- @[oh_jsvm_is_dataview](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/isdataview/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_IsDataview
static JSVM_Value IsDataView(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_IsDataview to check whether the given input is DataView data.
    bool result = false;
    JSVM_Status status = OH_JSVM_IsDataview(env, args[0], &result);
    JSVM_Value isDataView = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDataView);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDataView fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsDataView: %{public}d", result);
    }
    return isDataView;
}
// IsDataView register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDataView},
};
static JSVM_CallbackStruct *method = param;
// IsDataView method alias for TS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDataView", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *srcCallNative = R"JS(
let buffer = new ArrayBuffer(16);
let dataView = new DataView(buffer);
isDataView(dataView);
)JS";
```

Expected result:

```txt
JSVM IsDataView: 1
```

### OH_JSVM_IsTypedarray

Use **OH_JSVM_IsTypedarray** to check whether a JS object is a **TypedArray** object.

CPP code:

<!-- @[oh_jsvm_is_typedarray](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArray/istypedarray/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
// ...


// Sample method for OH_JSVM_IsTypedarray
static JSVM_Value IsTypedarray(JSVM_Env env, JSVM_CallbackInfo info)
{
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
        OH_LOG_INFO(LOG_APP, "JSVM IsTypedarray: %{public}d", result);
    }
    return isTypedArray;
}
// IsTypedarray register callback
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsTypedarray},
};
static JSVM_CallbackStruct *method = param;
// IsTypedarray method alias for TS calls
static JSVM_PropertyDescriptor descriptor[] = {
    {"isTypedarray", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS
const char *srcCallNative = R"JS(
isTypedarray(new Uint16Array([1, 2, 3, 4]));
)JS";
```

Expected result:

```txt
JSVM IsTypedarray: 1
```