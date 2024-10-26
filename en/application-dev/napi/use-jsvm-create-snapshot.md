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

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code related to the snapshot-related APIs.

### OH_JSVM_CreateSnapshot

Use **OH_JSVM_CreateSnapshot** to create a VM startup snapshot.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
#include <fstream>

// Register the CreateAndUseSnapshot callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateAndUseSnapshot},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createAndUseSnapshot and associate it with a callback. This allows the CreateAndUseSnapshot callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createAndUseSnapshot", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

static const int MAX_BUFFER_SIZE = 128;
// Allow the JSVM to call the CreateHelloString() function when needs, using the callback struct and external references.
static JSVM_Value CreateHelloString(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value outPut;
    OH_JSVM_CreateStringUtf8(env, "Hello world!", JSVM_AUTO_LENGTH, &outPut);
    return outPut;
}
// Enable the JSVM to call the bound function through external references.
static JSVM_CallbackStruct helloCb = {CreateHelloString, nullptr};
// externals is an array of external references that include a pointer to helloCb.
static intptr_t externals[] = {
    (intptr_t)&helloCb,
    0,
};

static JSVM_Value RunVMScript(JSVM_Env env, std::string &src)
{
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
    JSVM_Status status = OH_JSVM_CreateSnapshot(vm, 1, envs, &blobData, &blobSize);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "Test JSVM OH_JSVM_CreateSnapshot success, blobSize = : %{public}ld", blobSize);
    }
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
    if (result == nullptr) {
        OH_JSVM_ThrowError(env, nullptr, "Test JSVM RunVMSnapshot-RunVMScript result is nullptr");
        return;
    }
    char str[MAX_BUFFER_SIZE];
    OH_JSVM_GetValueStringUtf8(env, result, str, MAX_BUFFER_SIZE, nullptr);
    OH_LOG_INFO(LOG_APP, "Test JSVM RunVMSnapshot-RunVMScript result is: %{public}s", str);
    // Close and destroy the environment and the VM.
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);
    return;
}

static JSVM_Value CreateAndUseSnapshot(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Initialize OH_JSVM_Init(&initOptions) in the first initialization of RunJsVm() in the development process. The initialization can be performed only once.
    // The value assignment of initOptions is completed in the development process.
    // Create a VM snapshot and save it to a file.
    CreateVMSnapshot();
    // The snapshot records the specific JS execution environment and can be used to quickly restore the JS execution context environment across processes.
    RunVMSnapshot();
    JSVM_Value result = nullptr;
    OH_JSVM_CreateInt32(env, 0, &result);
    return result;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `
    createAndUseSnapshot()
`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM createAndUseSnapshot: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM createAndUseSnapshot error: %{public}s', error.message);
}
```
