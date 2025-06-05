# Working with VM Snapshots Using JSVM-API 

## Introduction

A JavaScript virtual machine (JSVM) snapshot records the state of a JSVM at a particular time point. The snapshot file contains information, such as the current heap memory, execution context, and function closure.

## Basic Concepts

- VM startup snapshot: a snapshot of the VM status at a specific time, including all internal status and data of the VM. The snapshot can be used to quickly restore the VM to the state it was when the snapshot was created.

It helps simplify complex programming tasks and shorten the creation time of a JS context, making the application more efficient and stable. 

## Available APIs

| API                      | Description                      |
|----------------------------|-------------------------------|
| OH_JSVM_CreateSnapshot     | Creates a VM startup snapshot.       |
|OH_JSVM_CreateEnvFromSnapshot| Creates an environment based on the start snapshot of a VM.|
## Example

### OH_JSVM_CreateSnapshot & OH_JSVM_CreateEnvFromSnapshot

Use **OH_JSVM_CreateSnapshot** to create a VM startup snapshot.

CPP code:

**NOTE**<br>Register the external dependencies of the JSVM with **initOptions.externalReferences** in **OH_JSVM_Init**.
```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <fstream>

#define LOG_DOMAIN 0x0202
#define LOG_TAG "TEST_TAG"

static int g_aa = 0;

#define CHECK_RET(theCall)                                                                                             \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if ((cond) != JSVM_OK) {                                                                                       \
            const JSVM_ExtendedErrorInfo *info;                                                                        \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                                      \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                         __FILE__, __LINE__, cond, info != nullptr ? info->errorMessage : "");                         \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (0)

#define CHECK(theCall)                                                                                                 \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if ((cond) != JSVM_OK) {                                                                                       \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d", __FILE__, __LINE__,  \
                         cond);                                                                                        \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (0)

// Call theCall and check whether the return value is JSVM_OK.
// If no, call GET_AND_THROW_LAST_ERROR to process the error and return retVal.
#define JSVM_CALL_BASE(env, theCall, retVal)                                                                           \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if (cond != JSVM_OK) {                                                                                         \
            const JSVM_ExtendedErrorInfo *info;                                                                        \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                                      \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                         __FILE__, __LINE__, cond, info != nullptr ? info->errorMessage : "");                         \
            return retVal;                                                                                             \
        }                                                                                                              \
    } while (0)

// Simplified version of JSVM_CALL_BASE, which returns nullptr.
#define JSVM_CALL(theCall) JSVM_CALL_BASE(env, theCall, nullptr)

static const int MAX_BUFFER_SIZE = 128;
// Allow the JSVM to call the CreateHelloString() function when needs, using the callback struct and external references.
static JSVM_Value CreateHelloString(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value outPut;
    OH_JSVM_CreateStringUtf8(env, "Hello world!", JSVM_AUTO_LENGTH, &outPut);
    return outPut;
}
// Enable the JSVM to call the bound function through external references.
static JSVM_CallbackStruct helloCb = {CreateHelloString, nullptr};

static intptr_t externals[] = {
    (intptr_t)&helloCb,
    0,
};

static JSVM_Value RunVMScript(JSVM_Env env, std::string &src) {
    // Open the handle scope.
    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    JSVM_Value jsStr = nullptr;
    OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsStr);
    // Compile the JS code.
    JSVM_Script script;
    OH_JSVM_CompileScript(env, jsStr, nullptr, 0, true, nullptr, &script);
    // Execute the JS code.
    JSVM_Value result = nullptr;
    OH_JSVM_RunScript(env, script, &result);
    // Close the handle scope.
    OH_JSVM_CloseHandleScope(env, handleScope);
    return result;
}
// Define OH_JSVM_CreateSnapshot.
static void CreateVMSnapshot() {
    // Create a JSVM instance and open the VM scope.
    JSVM_VM vm;
    JSVM_CreateVMOptions vmOptions;
    memset(&vmOptions, 0, sizeof(vmOptions));
    // Use isForSnapshotting to set whether the VM is used for creating snapshots.
    vmOptions.isForSnapshotting = true;
    OH_JSVM_CreateVM(&vmOptions, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);
    // Create a JS environment and open the environment scope.
    JSVM_Env env;
    // Register the native function as a method that can be called from JS.
    JSVM_PropertyDescriptor descriptor[] = {
        {"createHelloString", nullptr, &helloCb, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    };
    OH_JSVM_CreateEnv(vm, 1, descriptor, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // Use OH_JSVM_CreateSnapshot to create a VM startup snapshot.
    const char *blobData = nullptr;
    size_t blobSize = 0;
    JSVM_Env envs[1] = {env};
    OH_JSVM_CreateSnapshot(vm, 1, envs, &blobData, &blobSize);
    // Save the snapshot to a file.
    // Save the snapshot data to the /data/storage/el2/base/files/test_blob.bin directory, which is a sandbox directory.
    // For example, the bundle name is com.example.jsvm. The snapshot file is saved in /data/app/el2/100/base/com.example.jsvm/files/test_blob.bin.
    std::ofstream file("/data/storage/el2/base/files/test_blob.bin",
                       std::ios::out | std::ios::binary | std::ios::trunc);
    file.write(blobData, blobSize);
    file.close();
    // Close and destroy the environment and the VM.
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
}

static void RunVMSnapshot() {
    // The lifespan of blobData cannot be shorter than that of the VM.
    // Read the snapshot from the file.
    std::vector<char> blobData;
    std::ifstream file("/data/storage/el2/base/files/test_blob.bin", std::ios::in | std::ios::binary | std::ios::ate);
    size_t blobSize = file.tellg();
    blobData.resize(blobSize);
    file.seekg(0, std::ios::beg);
    file.read(blobData.data(), blobSize);
    file.close();
    OH_LOG_INFO(LOG_APP, "Test JSVM RunVMSnapshot read file blobSize = : %{public}ld", blobSize);
    // Use the snapshot data to create a VM instance.
    JSVM_VM vm;
    JSVM_CreateVMOptions vmOptions;
    memset(&vmOptions, 0, sizeof(vmOptions));
    vmOptions.snapshotBlobData = blobData.data();
    vmOptions.snapshotBlobSize = blobSize;
    OH_JSVM_CreateVM(&vmOptions, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);
    // Create an environment from the snapshot.
    JSVM_Env env;
    OH_JSVM_CreateEnvFromSnapshot(vm, 0, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // Execute the JS script. createHelloString() is defined in env of the snapshot record.
    std::string src = "createHelloString()";
    JSVM_Value result = RunVMScript(env, src);
    // Check the script execution result before closing the environment.
    char str[MAX_BUFFER_SIZE];
    OH_JSVM_GetValueStringUtf8(env, result, str, MAX_BUFFER_SIZE, nullptr);
    if (strcmp(str, "Hello world!") !=0) {
        OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d", __FILE__, __LINE__);   
    }
    // Close and destroy the environment and the VM.
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
    return;
}

static JSVM_Value AdjustExternalMemory(JSVM_Env env, JSVM_CallbackInfo info) {
    // If external dependencies exist when creating a VM snapshot, register the external dependencies with initOptions.externalReferences in OH_JSVM_Init.
    // Create a VM snapshot and save it to a file.
    CreateVMSnapshot();
    // The snapshot records the specific JS execution environment and can be used to quickly restore the JS execution context environment across processes.
    RunVMSnapshot();
    JSVM_Value result = nullptr;
    OH_JSVM_CreateInt32(env, 0, &result);
    return result;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = AdjustExternalMemory},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named adjustExternalMemory and associate it with a callback. This allows the AdjustExternalMemory callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"adjustExternalMemory", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call the C++ code from JS.
const char *srcCallNative = R"JS(adjustExternalMemory();)JS";

static int32_t TestJSVM() {
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;
    // Initialize the JSVM instance.
    if (g_aa == 0) {
        g_aa++;
        initOptions.externalReferences = externals;
      int argc = 0;
      char **argv = nullptr;
      initOptions.argc = &argc;
      initOptions.argv = argv;
      CHECK(OH_JSVM_Init(&initOptions));
    }
    // Create a JSVM environment.
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // Call the test function through the script.
    JSVM_Script script;
    JSVM_Value jsSrc;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // Destroy the JSVM environment.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}

static napi_value RunTest(napi_env env, napi_callback_info info)
{
    TestJSVM();
    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    OH_LOG_INFO(LOG_APP, "JSVM Init");
    napi_property_descriptor desc[] = {{"runTest", nullptr, RunTest, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
                                       
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```

ArkTS code:

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // runtest
            napitest.runTest();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
 
Log output when the screen is clicked once:
```ts
Test JSVM RunVMSnapshot read file blobSize = : 300064
```
Log output when the screen is clicked multiple times:
```ts
Test JSVM RunVMSnapshot read file blobSize = : 300176
Test JSVM RunVMSnapshot read file blobSize = : 300064
Test JSVM RunVMSnapshot read file blobSize = : 300160
Test JSVM RunVMSnapshot read file blobSize = : 300032
Test JSVM RunVMSnapshot read file blobSize = : 300176
Test JSVM RunVMSnapshot read file blobSize = : 300048
```
**blobSize** is the snapshot file size obtained through **file.tellg()** when the file is read.  
