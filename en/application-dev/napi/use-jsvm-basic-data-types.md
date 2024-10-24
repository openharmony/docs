# Creating Basic Data Types Using JSVM-API

## Introduction

In JavaScript (JS), the Integer type represents a number without a decimal point, and the Double type represents a number with a fractional part. Due to the limitation of the value storage mode of JS, very large or very small numbers cannot be accurately represented. In this case, you can use JSVM-API to represent large numbers in BigInt format.

## Basic Concepts

Before using JSVM-API to create and obtain numbers, you need to understand the following concepts:

- Number type<br>When using JSVM-API, you may need to convert values of number types between C and JS. When converting the data, pay attention to the data range, signedness (signed or unsigned), and precision (single or double precision).
- Error handling<br>You also need to use JSVM-API to capture and handle errors that may occur during the conversion. For example, when an integer is created, you may need to capture and handle memory allocation failures or other runtime errors.
- Interaction between JS and JSVM-API<br>During the development, you need to consider the interaction between JS and JSVM-API, including how to pass the data of the number type and return the correct value.

## Available APIs

| API                 | Description                                       |
| --------------------- | -----------------------------------------------|
| OH_JSVM_GetValueUint32 | Obtains the C Uint32 primitive equivalent of the given JS number.  |
| OH_JSVM_GetValueInt32  | Obtains the C Int32 primitive equivalent of the given JS number.   |
| OH_JSVM_GetValueInt64  | Obtains the C Int64 primitive equivalent of the given JS number.   |
| OH_JSVM_GetValueDouble | Obtains the C Double primitive equivalent of the given JS number.  |
| OH_JSVM_CreateInt32     | Creates a JS number object from a C Int32_t object. |
| OH_JSVM_CreateUint32    | Creates a JS number object from a C Uint32_t object.|
| OH_JSVM_CreateInt64     | Creates a JS number object from a C Int64_t object. |
| OH_JSVM_CreateDouble    | Creates a JS number object from a C Double object. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs for manipulating basic data types.

### OH_JSVM_GetValueUint32

Use **OH_JSVM_GetValueUint32** to obtain a 32-bit unsigned integer from a JS number.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueUint32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueUint32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueUint and associate it with a callback. This allows the GetValueUint callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueUint32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueUint32.
static JSVM_Value GetValueUint32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the parameter of the Number type.
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    // Parse the input parameter.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    uint32_t number = 0;
    // Obtain a 32-bit unsigned integer from the input parameter.
    JSVM_Status status = OH_JSVM_GetValueUint32(env, argv[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueUint32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueUint32 success: %{public}d", number);
    }
    return argv[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let num = 123;
let script: string = `
   function testGetValueUint32(num) {
       return getValueUint32(num);
   }
   testGetValueUint32(${num})
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testGetValueUint32: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testGetValueUint32 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueInt32

Use **OH_JSVM_GetValueInt32** to obtain a C int32 value from a JS number.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueInt32 and associate it with a callback. This allows the GetValueInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueInt32.
static JSVM_Value GetValueInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int32_t result32 = 0;
    // Parse the input parameter.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the input parameter into a C int32 value.
    JSVM_Status status = OH_JSVM_GetValueInt32(env, args[0], &result32);
    if (status != JSVM_OK) {
        return nullptr;
    }
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt32 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt32 success: %{public}d", result32);
    }
    return args[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let num = -123;
let script: string = `
   function testGetValueInt32(num) {
       return getValueInt32(num);
   }
   testGetValueInt32(${num})
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testGetValueInt32: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testGetValueInt32 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueInt64

Use **OH_JSVM_GetValueInt64** to obtain a C int64 value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueInt64 and associate it with a callback. This allows the GetValueInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueInt64.
static JSVM_Value GetValueInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    int64_t result64 = 0;
    // Parse the input parameter.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Convert the input parameter into a C int64 value.
    JSVM_Status status = OH_JSVM_GetValueInt64(env, args[0], &result64);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetValueInt64 fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetValueInt64 success: %{public}d", result64);
    }
    return args[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let num = -110;
let script: string = `
   function testGetValueInt64(num) {
       return getValueInt64(num);
   }
   testGetValueInt64(${num})
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testGetValueInt64: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testGetValueInt64 error: %{public}s', error.message);
}
```

### OH_JSVM_GetValueDouble

Use **OH_JSVM_GetValueDouble** to obtain a C double value from a JS value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetDouble callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDouble},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getDouble and associate it with a callback. This allows the GetDouble callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueDouble.
static JSVM_Value GetDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    double value;
    JSVM_Status status = OH_JSVM_GetValueDouble(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetDouble fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetDouble success: %{public}f", value);
    }
    return args[0];
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let num = -110.0456;
let script: string = `
   function testGetDouble(num) {
       return getDouble(num);
   }
   testGetDouble(${num})
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testGetDouble: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testGetDouble error: %{public}s', error.message);
}
```

### OH_JSVM_CreateInt32

Use **OH_JSVM_CreateInt32** to create a JS number from a 32-bit signed integer.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createInt32 and associate it with a callback. This allows the CreateInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateInt32.
static JSVM_Value CreateInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    // int32_t represents a 32-bit signed integer, ranging from -2^31 to 2^31 - 1, that is, -2147483648 to 2147483647. 
    int32_t value = -20;
    // Create a JS Int32 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt32 fail");
    } else {
        int32_t number = 0;
        OH_JSVM_GetValueInt32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt32 success: %{public}d", number);
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
   function testCreateInt32() {
       return createInt32();
   }
   testCreateInt32()
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateInt32: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateInt32 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateUint32

Use **OH_JSVM_CreateUint32** to create a JS number from a 32-bit unsigned integer.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateUInt32 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateUInt32},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createUInt32 and associate it with a callback. This allows the CreateUInt32 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createUInt32", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateUint32.
static JSVM_Value CreateUInt32(JSVM_Env env, JSVM_CallbackInfo info)
{
    
    // If the uint32_t type is used to represent -26, overflow occurs. Modulo operation is performed on the result to convert the binary complement of the negative number to a positive number. That is, 4294967270 will be returned.
    // uint32_t represents a 32-bit unsigned integer, ranging from 0 to 2^32 - 1, that is, 0 to 4294967295.     
    uint32_t value = 26;
    // Create a JS Uint32 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateUint32(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateUInt32 fail");
    } else {
        uint32_t number = 0;
        OH_JSVM_GetValueUint32(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateUInt32 success: %{public}d", number);
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
   function testCreateUInt32() {
       return createUInt32();
   }
   testCreateUInt32()
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateUInt32: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateUInt32 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateInt64

Use **OH_JSVM_CreateInt64** to create a JS number from a 64-bit signed integer.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateInt64 callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateInt64},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createInt64 and associate it with a callback. This allows the CreateInt64 callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createInt64", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateInt64.
static JSVM_Value CreateInt64(JSVM_Env env, JSVM_CallbackInfo info)
{
    // int64 represents a 64-bit signed integer, ranging from -2^63 to 2^63 - 1, that is, -9223372036854775808 to 9223372036854775807.
    int64_t value = 2147483648;
    // Create a JS Int64 number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateInt64(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateInt64 fail");
    } else {
        int64_t number = 0;
        OH_JSVM_GetValueInt64(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateInt64 success: %{public}ld", value);
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
   function testCreateInt64() {
       return createInt64();
   }
   testCreateInt64()
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateInt64: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateInt64 error: %{public}s', error.message);
}
```

### OH_JSVM_CreateDouble

Use **OH_JSVM_CreateDouble** to create a JS number from a double-precision floating-point number.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateDouble callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDouble},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDouble and associate it with a callback. This allows the CreateDouble callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDouble", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateDouble.
static JSVM_Value CreateDouble(JSVM_Env env, JSVM_CallbackInfo info)
{
    double value = 1.234;
    // Create a JS double number.
    JSVM_Value result = nullptr;
    JSVM_Status status = OH_JSVM_CreateDouble(env, value, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateDouble fail");
    } else {
        double number = 0;
        OH_JSVM_GetValueDouble(env, result, &number);
        OH_LOG_INFO(LOG_APP, "JSVM CreateDouble success: %{public}f", number);
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
   function testCreateDouble() {
       return createDouble();
   }
   testCreateDouble()
   `;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM testCreateDouble: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM testCreateDouble error: %{public}s', error.message);
}
```
