# Using N-APIs in Application Projects

In OpenHarmony, you can use the N-APIs in C APIs to implement interaction between ArkTS/TS/JS and C/C++. The  N-API names are the same as those in the third-party **Node.js**. Currently, OpenHarmony supports some N-APIs. For details about the APIs supported, see [arkui_napi](https://gitee.com/openharmony/arkui_napi/blob/master/libnapi.ndk.json).

## How to Develop

The DevEco Studio provides a default project that uses N-APIs. You can choose **File** > **New** > **Create Project** to create a Native C++ project. After the project is created, the **cpp** directory is generated in the **entry/src/main** directory. You can use the N-APIs to develop C/C++ code (native code).

You can import the native .so file for ArkTS/TS/JS programming. For example, you can **import hello from 'libhello.so'** to use the **libhello.so** capability and pass the ArkTS/TS/JS object named **hello** to the ArkTS/TS/JS APIs of the application. You can use this object to invoke the N-APIs in **cpp**.

## Basic Features
The N-APIs implement interaction between ArkTS/TS/JS and C/C++. The following provides two **HelloWorld** project examples:
1. Define an N-API method **Add()**, which is called by ArkTS with two numbers passed in. The N-API **Add**() method adds the two numbers and returns the result to ArkTS.
2. Define an N-API method named **NativeCallArkTS**, which is called by ArkTS with an ArkTS function passed in. The **NativeCallArkTS** method invokes this ArkTS function and returns the result to ArkTS.

The following describes:
1. How an ArkTS method invokes a C++ method.
2. How a C++ method invokes an ArkTS method.

The project has the following files:
- **entry\src\main\cpp\hello.cpp**: contains the N-API logic.
- **entry\src\main\ets\pages\index.ets**: contains the ArkTS logic.
- **entry\src\main\cpp\types\libentry\index.d.ts**: contains the declaration of the N-APIs exposed to ArkTS.

The following provides the comments for the files. Other parts in the project are the same as those in the native default project.

```C++
// entry\src\main\cpp\hello.cpp
// Include the N-API header file.
#include "napi/native_api.h"

// N-API method, which has only two input parameters. You do not need to modify them.
// napi_env is the current running context.
// napi_callback_info contains related information, including parameters passed from ArkTS.
static napi_value Add(napi_env env, napi_callback_info info)
{
    // Number of parameters to be obtained from ArkTS. napi_value can be regarded as the representation of the ArkTS value in the N-API method.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    
    // From info(), obtain the parameters passed from ArkTS. In this example, two ArkTS parameters, arg[0] and arg[1], are obtained.
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);

    // Convert the obtained ArkTS parameters to the type that can be processed by N-API. In this example, the two numbers passed from ArkTS are converted to the double type.
    double value0;
    napi_get_value_double(env, args[0], &value0);

    double value1;
    napi_get_value_double(env, args[1], &value1);
    
    // N-API service logic, which is adding two numbers in this example.
    double nativeSum = value0 + value1;
    
    // Convert the N-API service logic processing result to an ArkTS value and return the value to ArkTS.
    napi_value sum;
    napi_create_double(env, nativeSum , &sum);
    return sum;
}

static napi_value NativeCallArkTS(napi_env env, napi_callback_info info)
{
    // Number of parameters to be obtained from ArkTS. napi_value can be regarded as the representation of the ArkTS value in the N-API method.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    // From info(), obtain the parameters passed from ArkTS. In this example, one ArkTS parameter, arg[0], is obtained.
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    
    // Create an ArkTS number as the input parameter of the ArkTS function.
    napi_value argv = nullptr;
    napi_create_int32(env, 10, &argv);
    
    napi_value result = nullptr;
    // Invoke the ArkTS function in the N-API method, save the return value in result, and return result to ArkTS.
    napi_call_function(env, nullptr, args[0], 1, &argv, &result);
    
    return result;
}

EXTERN_C_START
// Init() hooks native methods, such as Add and NativeCallArkTS, in exports. exports is the ArkTS object obtained after you import the native capabilities.
static napi_value Init(napi_env env, napi_value exports)
{
    // Function description struct. The third parameter "Add" is the N-API method.
    // The first parameter "add" is the name of the ArkTS method.
    napi_property_descriptor desc[] = {
        { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "nativeCallArkTS", nullptr, NativeCallArkTS, nullptr, nullptr, nullptr, napi_default, nullptr },
    };
    // Hook the N-API method to the ArkTS object exports.
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

// Information about the module that loads the data. Record information such as the Init() function and module name.
static napi_module demoModule = {
    .nm_version =1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

// When the .so file is opened, the function is automatically called to register the demoModule module.
extern "C" __attribute__((constructor)) void RegisterHelloModule(void)
{
    napi_module_register(&demoModule);
}
```

```js
// entry\src\main\ets\pages\index.ets

import hilog from '@ohos.hilog';
// Import the native capabilities.
import entry from 'libentry.so'

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        // The first button calls the add() method, which uses the N-API Add method to add the two numbers.
        Button('ArkTS call C++')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
            hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', entry.add(2, 3));
          })
        // The second button calls the nativeCallArkTS() method, which uses the N-API NativeCallArkTS method to execute the ArkTS function.
        Button('C++ call ArkTS')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
            let ret = entry.nativeCallArkTS((value)=>{return value * 2;});
            hilog.info(0x0000, 'testTag', 'Test NAPI nativeCallArkTS ret = %{public}d', ret);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}

```

```js
// entry\src\main\cpp\types\libentry\index.d.ts
// Declare the N-APIs exposed to ArkTS.
export const add: (a: number, b: number) => number;
export const nativeCallArkTS: (a: object) => number;
```

## Development Guidelines

### Registration

* To prevent conflicts with symbols in the .so file, add "static" to the function (such as the Init function) corresponding to **nm_register_func**. 
* The entry of module registration, that is, the function name modified by **\_\_attribute\_\_((constructor))** (for example, the **RegisterHelloModule** function), must be unique.

### .so Naming Rules

The .so file names must comply with the following rules:

* Each module has a .so file.
* The **nm_modname** field in **napi_module** must be the same as the module name. For example, if the module name is **hello**, name the .so file **libhello.so**. The sample code for importing the .so file is **import hello from 'libhello.so'**.

### Constraints on JS Object Threads

The ArkCompiler protects JS object threads. Improper use may cause an application crash. Observe the following rules:

* The N-APIs can be used only by JS threads.
* **env** is bound to a thread and cannot be used across threads. The JS object created by an N-API can be used only in the thread, in which the object is created, that is, the JS object is bound to the **env** of the thread.

### Header File Import

Import **napi/native_api.h**. Otherwise, an error indicating that the N-API cannot be found will be reported.
